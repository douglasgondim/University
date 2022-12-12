/* 	José Douglas Gondim Soares MAT 416753
	Fernanda Costa de Sousa    MAT 411684 
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <locale.h>
#include "fila_de_threads.h"

// define qual prioridade executa agora
int fila_prioridade;

// quantum do processador e tempo de simulação
int quantum, tempo_sim;

// variaveis que guardam clock do inicio e fim da simulação 
time_t inicio_simulacao, fim_simulacao;

// 4 filas de prioridade e uma de bloqueados
Fila* fila_4; // fila de maior prioridade
Fila* fila_3;
Fila* fila_2;
Fila* fila_1; // fila de menor prioridade
Fila* fila_bloqueados; // fila de threads bloqueadas


							// função que toda thread executa
void* imprime(void* thread){
	// variável que guarda a ultima intrução executada
	int instrucao = 0;
	// converte para tipo Thread a thread que imprime recebe como parâmetro
	Thread* thread_struct = (Thread*) thread;

	// enqunato a sumulação não acabar
	while(inicio_simulacao<fim_simulacao){
		// se a thread ainda não executou todas as instruções
		if(instrucao< thread_struct->num_instrucoes){
			// trava o semaforo da thread_struct
			pthread_mutex_lock(&thread_struct->mutex);
			// espera por sinal do escalonador para executar
			pthread_cond_wait(&thread_struct->permissao, &thread_struct->mutex);
			// atualizo o ciclo de clock do processador atual 
			inicio_simulacao = clock();
			// se a simulação não acabou e a thread não está bloqueada
			if(inicio_simulacao<fim_simulacao && thread_struct->estado !=2){
				// muda o estado da thread para executando
				thread_struct->estado = 0;
				// imprimir numero de thread e instrução que está executanto
				printf("Sou a thread [%d] e estou executando a instrucao [%d]\n", thread_struct->thread_num, instrucao);
				// incrementa a intrução
				instrucao++;
				// muda estado da thread de executando para pronto
				thread_struct->estado = 1;
			}
			// atualiza o clock da variavel inicio_simulacao
			inicio_simulacao = clock();
			// destravo semáforo da thread_struct
			pthread_mutex_unlock(&thread_struct->mutex);
		}else{
			// se a thread ja executou todas as instruções, devemos bloquea-la
			// muda estado da thread para bloqueado
			thread_struct->estado = 2;		
			// restaura o valor de instrução para 0
			instrucao = 0;
		}
	}
	// se a simulação acabar, devemos matar todas as threads
	exit(EXIT_SUCCESS);
}


								// escalonador
void* escalonador(){
	// declara variaveis que guarda ciclo de clock do inicio de execução da thread
	// e em que ciclo de clock ela deve ser interrompida
	time_t inicio_thread_time, fim_thread_time;

	// enquanto a simulação não tiver acabado
	while(inicio_simulacao<fim_simulacao){
		// se a fila 4 tiver elementos e a prioridade executando for a 4 e a simulação
		// não tiver acabado
		if(fila_4->inicio!=NULL && fila_prioridade==4 && inicio_simulacao<fim_simulacao){
			// remove a thread no inicio da fila 4 e faz o ponteiro executa apontar pra ela
			Thread* executa = removerFila(fila_4);
			// guarda o ciclo de clock que a thread inicia
			inicio_thread_time = clock();

			// calcula o ciclo de clock que a thread precisa encerrar
			fim_thread_time = inicio_thread_time + (CLOCKS_PER_SEC*0.001)*(long)quantum;

			// enquanto o quantum não acabar e a thread não estiver bloqueada
			while(inicio_thread_time<fim_thread_time && executa->estado != 2){
				// trava o mutex da thread --executa--
				pthread_mutex_lock(&executa->mutex);
				
				// manda o sinal para a thread --executa-- executar
				pthread_cond_signal(&executa->permissao);

				// atualiza o ciclo de clock do inicio da thread	
				inicio_thread_time = clock();
				// destrava o semáforo da thread
				pthread_mutex_unlock(&executa->mutex);
	
			}

			// a thread estiver bloqueada
			if(executa->estado==2){
				// adiciona na fila de bloqueados
				addFila(fila_bloqueados, executa);
				// grava o momento que ela entrou no bloqueados
				executa->clock_saida = clock();
				// calcula quando ela deve sair do bloqueados a partir do seu tempo de E/S
				executa->clock_retorno = executa->clock_saida + (CLOCKS_PER_SEC*0.001)*(long)executa->tempo_ES;
			}else{
				// se a thread não estiver bloqueada, adiciona ela de volta na sua fila
				addFila(fila_4, executa);
			}

			// atualiza o inicio da simulação
			inicio_simulacao = clock();

		}


		// se a fila 4 estiver vazia e a fila de bloqueado tiver elementos
		if(fila_4->inicio==NULL && fila_bloqueados->inicio != NULL){
			// muda prioridade que executa no momento para 3
			fila_prioridade = 3;
		}


		// se fila 3 não estiver vazia e a fila de prioridade executando seja a 3 e a simulação
		// não tiver acabado
		if(fila_3->inicio!=NULL && fila_prioridade==3 && inicio_simulacao<fim_simulacao){
			// remove thread do inicio da fila 3 e a chama de executa
			Thread* executa = removerFila(fila_3);
			// guarda o ciclo de clock do inicio da thread
			inicio_thread_time = clock();
			// calcula em que ciclo de clock a thread deve ser interrompida
			fim_thread_time = inicio_thread_time + (CLOCKS_PER_SEC*0.001)*(long)quantum;

			// Enquanto o quantum da thread não estourar e ela não estiver bloqueada
			while(inicio_thread_time<fim_thread_time && executa->estado != 2){
				// trava o mutex daquela thread
				pthread_mutex_lock(&executa->mutex);
				// manda sinal para que ela execute
				pthread_cond_signal(&executa->permissao);
				// atualiza o clock do inicio da thread
				inicio_thread_time = clock();
				// destrava o semáforo da thread
				pthread_mutex_unlock(&executa->mutex);
	
			}

			// se a thread estiver bloqueada
			if(executa->estado==2){
				// adiciona na fila de bloqueados
				addFila(fila_bloqueados, executa);
				// guarda tempo que a thread enra na fila de bloqueados
				executa->clock_saida = clock();
				// calcula quando ele deve sair da fila de bloqueados
				executa->clock_retorno = executa->clock_saida + (CLOCKS_PER_SEC*0.001)*(long)executa->tempo_ES;
			}else{
				// se a thread não estiver bloqueada
				// adiciona ela de volta na fila 3
				addFila(fila_3, executa);
			}
			// atualiza o ciclo de clock do inicio da simulacao
			inicio_simulacao = clock();

		}
		

		// se as filas 4 e 3 estiverem vazias e a de bloqueado tiver elementos
		if(fila_4->inicio==NULL && fila_3->inicio==NULL && fila_bloqueados->inicio != NULL){
			// muda prioridade que executa para 2
			fila_prioridade = 2;
		}




		// se a fila 2 tiver elementos e a prioridade executando for a 2 e a simulação
		// não tiver acabado
		if(fila_2->inicio!=NULL && fila_prioridade==2 && inicio_simulacao<fim_simulacao){
			// remove a thread no inicio da fila 2 e faz o ponteiro executa apontar pra ela
			Thread* executa = removerFila(fila_2);
			// guarda o ciclo de clock que a thread inicia
			inicio_thread_time = clock();

			// calcula o ciclo de clock que a thread precisa encerrar
			fim_thread_time = inicio_thread_time + (CLOCKS_PER_SEC*0.001)*(long)quantum;

			// enquanto a simulação não acabar e a thread não estiver bloqueada
			while(inicio_thread_time<fim_thread_time && executa->estado != 2){
				// trava o mutex da thread --executa--
				pthread_mutex_lock(&executa->mutex);
				
				// manda o sinal para a thread --executa-- executar
				pthread_cond_signal(&executa->permissao);

				// atualiza o ciclo de clock do inicio da thread	
				inicio_thread_time = clock();
				// destrava o semáforo da thread
				pthread_mutex_unlock(&executa->mutex);
	
			}

			// a thread estiver bloqueada
			if(executa->estado==2){
				// adiciona na fila de bloqueados
				addFila(fila_bloqueados, executa);
				// grava o momento que ela entrou no bloqueados
				executa->clock_saida = clock();
				// calcula quando ela deve sair do bloqueados a partir do seu tempo de E/S
				executa->clock_retorno = executa->clock_saida + (CLOCKS_PER_SEC*0.001)*(long)executa->tempo_ES;
			}else{
				// se a thread não estiver bloqueada, adiciona ela de volta na sua fila
				addFila(fila_2, executa);
			}

			// atualiza o inicio da simulação
			inicio_simulacao = clock();

		}

		
		// se as filas 4, 3, 2 estiverem vazias e a de bloqueados tiver elementos
		if(fila_4->inicio==NULL && fila_3->inicio==NULL && fila_2->inicio == NULL && fila_bloqueados->inicio != NULL){
			// muda prioridade que executa para 1
			fila_prioridade = 1;
		}


		// se fila 1 não estiver vazia e a fila de prioridade executando seja a 1 e a simulação
		// não tiver acabado
		if(fila_1->inicio!=NULL && fila_prioridade==1 && inicio_simulacao<fim_simulacao){
			// remove thread do inicio da fila 1 e a chama de executa
			Thread* executa = removerFila(fila_1);
			// guarda o ciclo de clock do inicio da thread
			inicio_thread_time = clock();
			// calcula em que ciclo de clock a thread deve ser interrompida
			fim_thread_time = inicio_thread_time + (CLOCKS_PER_SEC*0.001)*(long)quantum;

			// Enquanto o quantum da thread não estourar e ela não estiver bloqueada
			while(inicio_thread_time<fim_thread_time && executa->estado != 2){
				// trava o mutex daquela thread
				pthread_mutex_lock(&executa->mutex);
				// manda sinal para que ela execute
				pthread_cond_signal(&executa->permissao);
				// atualiza o clock do inicio da thread
				inicio_thread_time = clock();
				// destrava o semáforo da thread
				pthread_mutex_unlock(&executa->mutex);
	
			}

			// se a thread estiver bloqueada
			if(executa->estado==2){
				// adiciona na fila de bloqueados
				addFila(fila_bloqueados, executa);
				// guarda tempo que a thread enra na fila de bloqueados
				executa->clock_saida = clock();
				// calcula quando ele deve sair da fila de bloqueados
				executa->clock_retorno = executa->clock_saida + (CLOCKS_PER_SEC*0.001)*(long)executa->tempo_ES;
			}else{
				// se a thread não estiver bloqueada
				// adiciona ela de volta na fila 1
				addFila(fila_1, executa);
			}
			// atualiza o ciclo de clock do inicio da simulacao
			inicio_simulacao = clock();

		}


		// se a fila de bloqueados tiver elementos
		if(fila_bloqueados->inicio != NULL){
			//remove o primeiro elento da lista de bloqueados
			Thread* thread_bloqueada = fila_bloqueados->inicio;
			// atualza o tempo de saida da fila de prontos da thread
			thread_bloqueada->clock_saida = clock();

			// se a prioridade da thread que esta bloqueada for maior ou igual
			// a prioridade que está executando e ela estiver pronta pra voltar
			if(thread_bloqueada->prioridade>=fila_prioridade
			&& thread_bloqueada->clock_saida>thread_bloqueada->clock_retorno){
				// fila_prioridade recebe a prioridade da thread
				fila_prioridade = thread_bloqueada->prioridade;
				// muda o estado da thread para pronta
				thread_bloqueada->estado=1;
			
				// se a prioridade da thread removida for 4, adiciona ela na fila 4
				// se for 3, na fila 3, se 2, na fila 2 e se 1, na fila 1  
				if(thread_bloqueada->prioridade==4){
					addFila(fila_4, removerFila(fila_bloqueados));
				}else if(thread_bloqueada->prioridade==3){
					addFila(fila_3, removerFila(fila_bloqueados));
				}else if(thread_bloqueada->prioridade==2){
					addFila(fila_2, removerFila(fila_bloqueados));
				}else if(thread_bloqueada->prioridade==1){
					addFila(fila_1, removerFila(fila_bloqueados));
				}

			}else{
				// se a thread tiver menor prioridade do que a fila que está executando
				// ou ela não estiver pronta para voltar

				// adiciono a thread de volta na fila de bloqueados
				addFila(fila_bloqueados, removerFila(fila_bloqueados));
			}
		}

		
		// atualiza o clock da variavel inicio_simulacao
		inicio_simulacao = clock();

	}
	// se o tempo de simulação acabar, matar todas as threads
	exit(EXIT_SUCCESS);

}


int main(){
	// numero de threads a serem criads
	int num_threads;

	// aloca espaço para 4 filas de prioridade e uma de bloqueados
	fila_4 = criarFila();
	fila_3 = criarFila();
	fila_2 = criarFila();
	fila_1 = criarFila();
	fila_bloqueados = criarFila();

	// vetor de Threads
	Thread* thread_structs;

	// ponteiro para vetor de thread ids
	pthread_t* tids;

	// permite textos com carcteres especiais do Português
	setlocale(LC_ALL, "Portuguese");

	// lê o número de threads a serem criadas
	printf("Digite o número de threads que deseja criar\n");
	scanf("%d", &num_threads);

	// aloca espaço para o vetor de thread ids
	tids = malloc(num_threads*sizeof(pthread_t));

	//aloca espaço para o vetor de thread
	thread_structs = malloc(num_threads*sizeof(Thread));

	// para todos os elementos do vetor thread
	for(int i=0;i<num_threads;i++){

		// cada thread recebe um número em ordem
		thread_structs[i].thread_num = i;

		// inicializa mutex de cada thread
		pthread_mutex_init(&thread_structs[i].mutex, NULL);

		//inicializa variavel de condição de cada thread
		pthread_cond_init (&thread_structs[i].permissao, NULL);

		// inicializa o ponteiro prox de cada thread com nulo
		thread_structs[i].prox = NULL;

		// cada thread recebe status de pronto
		thread_structs[i].estado = 1;		
	}
	// seta fila de prioridade para começar a executar em 1
	fila_prioridade = 1;

	// lê a prioridade de cada thread no vetor
	printf("Digite a prioridade de cada thread (MAIOR [4] e MENOR [1])\n");
	for(int i=0;i<num_threads;i++){
		scanf("%d", &thread_structs[i].prioridade);
		// se a ultima prioridade lida for maior do que fila_prioridade
		// atualiza o valor de fila_prioridade
		if(thread_structs[i].prioridade>fila_prioridade){
			fila_prioridade = thread_structs[i].prioridade;
		}
	}

	// lê o numero de instruções que cada thread executa
	printf("Digite o número de instruções que cada thread executa antes de pedir E/S\n");
	for(int i=0;i<num_threads;i++){
		scanf("%d", &thread_structs[i].num_instrucoes);
	}

	// lê o tempo de E/S de cada thread (tempo gasto na fila de bloqueados)
	printf("Digite o tempo de E/S de cada thread (ms)\n");
	for(int i=0;i<num_threads;i++){
		scanf("%d", &thread_structs[i].tempo_ES);
	
		// dependendo da prioridade de cada thread, a adiciona em sua respectiva fila
		if(thread_structs[i].prioridade==4){
			addFila(fila_4, &thread_structs[i]);
		}else if(thread_structs[i].prioridade==3){
			addFila(fila_3, &thread_structs[i]);
		}else if(thread_structs[i].prioridade==2){
			addFila(fila_2, &thread_structs[i]);
		}else if(thread_structs[i].prioridade==1){
			addFila(fila_1, &thread_structs[i]);
		}
	}

	// lê o quantum do processador em milisegundos
	printf("Digite o valor do quantum (ms)\n");
	scanf("%d", &quantum);

	// lê o tempo da simulação em milisegundos
	printf("Digite o tempo da simulacao (ms)\n");
	scanf("%d", &tempo_sim);

	// marca o inicio da simulação (numero de clock que o programa está agora)
	inicio_simulacao = clock();

	// marca quando ela deve acabar (tempo de simulação)
	//ciclo de clock final
	fim_simulacao = inicio_simulacao + (CLOCKS_PER_SEC*0.001)*(long)tempo_sim;

	// cria escalonador
	pthread_t escalonador_tid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_create(&escalonador_tid, &attr, escalonador, NULL);


	//cria cada uma das threads
	for(int i=0; i<num_threads;i++){
		pthread_attr_t attr;
		pthread_attr_init(&attr);
		pthread_create(&tids[i], &attr, imprime, &thread_structs[i]);	
	}

	//espera por cada thread
	pthread_join(escalonador_tid, NULL);
	
	// espera por todas as threads
	for(int i=0;i<num_threads;i++){
		pthread_join(tids[i], NULL);

	}

	return 0;
}