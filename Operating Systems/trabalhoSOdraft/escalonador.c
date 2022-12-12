#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include "fila_de_threads.h"

// define qual prioridade executa agora
int fila_prioridade;

// quantum do processador e tempo de simulação
int quantum, tempo_sim;

// variaveis que guardam clock do inicio e fim da simulação 
time_t inicio_simulacao, fim_simulacao;

// 4 filas de prioridade e uma de bloqueados
Fila* fila_4;
Fila* fila_3;
Fila* fila_2;
Fila* fila_1;
Fila* fila_bloqueados;



// função que toda thread executa
void* imprime(void* thread){
	int instrucao = 0;
	// converte para tipo Thread a thread que imprime recebe como parâmetro
	Thread* thread_struct = (Thread*) thread;

	while(inicio_simulacao<fim_simulacao){
		for(int i=0;i<thread_struct->num_instrucoes;i++){
			if(inicio_simulacao<fim_simulacao && thread_struct->estado!=3){
				pthread_mutex_lock(&thread_struct->mutex);
				pthread_cond_wait(&thread_struct->permissao, &thread_struct->mutex);
				if(inicio_simulacao<fim_simulacao){
					thread_struct->estado = 0;
					printf("Sou a thread [%d] e estou executando a instrucao [%d]\n", thread_struct->thread_num, instrucao);
					instrucao++;
				}
				thread_struct->estado = 1;
				inicio_simulacao = clock();
				pthread_mutex_unlock(&thread_struct->mutex);

			}
			if(inicio_simulacao>fim_simulacao){
				fila_prioridade = -1;
				
			}


		}
		thread_struct->estado = 2;		
		// printf("bloqueia\n");
		instrucao = 0;
	}
	exit(EXIT_SUCCESS);
}

// escalonador
void* escalonador(){
	time_t inicio_thread_time, fim_thread_time;

	while(inicio_simulacao<fim_simulacao){
		while(fila_4->inicio!=NULL && fila_prioridade==4 && inicio_simulacao<fim_simulacao){
			Thread* executa = removerFila(fila_4);
			inicio_thread_time = clock();

			fim_thread_time = inicio_thread_time + (CLOCKS_PER_SEC*0.001)*(long)quantum;

			while(inicio_thread_time<fim_thread_time){
		
				pthread_mutex_lock(&executa->mutex);
				pthread_cond_signal(&executa->permissao);
				inicio_thread_time = clock();
				pthread_mutex_unlock(&executa->mutex);

			}
			if(executa->estado==2 || inicio_simulacao>fim_simulacao){
				addFila(fila_bloqueados, executa);
				executa->clock_saida = clock();
				executa->clock_retorno = executa->clock_saida + (CLOCKS_PER_SEC*0.001)*(long)executa->tempo_ES;
			}else{
				addFila(fila_4, executa);
			}

			if(fila_bloqueados->inicio != NULL){
				fila_bloqueados->inicio->clock_saida = clock();
				if(fila_bloqueados->inicio->prioridade>=fila_prioridade
				 && fila_bloqueados->inicio->clock_saida>fila_bloqueados->inicio->clock_retorno){

					fila_prioridade = fila_bloqueados->inicio->prioridade;

					if(fila_bloqueados->inicio->prioridade==4){
						addFila(fila_4, removerFila(fila_bloqueados));
					}else if(fila_bloqueados->inicio->prioridade==3){
						addFila(fila_3, removerFila(fila_bloqueados));
					}else if(fila_bloqueados->inicio->prioridade==2){
						addFila(fila_2, removerFila(fila_bloqueados));
					}else if(fila_bloqueados->inicio->prioridade==1){
						addFila(fila_1, removerFila(fila_bloqueados));
					}

				}
			}

			inicio_simulacao = clock();

		}

		if(fila_4->inicio==NULL){
			fila_prioridade = 3;
		}


		while(fila_3->inicio!=NULL && fila_prioridade==3 && inicio_simulacao<fim_simulacao){
			Thread* executa = removerFila(fila_3);
			inicio_thread_time = clock();

			fim_thread_time = inicio_thread_time + (CLOCKS_PER_SEC*0.001)*(long)quantum;

			while(inicio_thread_time<fim_thread_time){
		
				pthread_mutex_lock(&executa->mutex);
				pthread_cond_signal(&executa->permissao);
				inicio_thread_time = clock();
				pthread_mutex_unlock(&executa->mutex);

			}
			if(executa->estado==2 || inicio_simulacao>fim_simulacao){
				addFila(fila_bloqueados, executa);
				executa->clock_saida = clock();
				executa->clock_retorno = executa->clock_saida + (CLOCKS_PER_SEC*0.001)*(long)executa->tempo_ES;
			}else{
				addFila(fila_3, executa);
			}

			if(fila_bloqueados->inicio != NULL){
				fila_bloqueados->inicio->clock_saida = clock();
				if(fila_bloqueados->inicio->prioridade>=fila_prioridade
				 && fila_bloqueados->inicio->clock_saida>fila_bloqueados->inicio->clock_retorno){

					fila_prioridade = fila_bloqueados->inicio->prioridade;

					if(fila_bloqueados->inicio->prioridade==4){
						addFila(fila_4, removerFila(fila_bloqueados));
					}else if(fila_bloqueados->inicio->prioridade==3){
						addFila(fila_3, removerFila(fila_bloqueados));
					}else if(fila_bloqueados->inicio->prioridade==2){
						addFila(fila_2, removerFila(fila_bloqueados));
					}else if(fila_bloqueados->inicio->prioridade==1){
						addFila(fila_1, removerFila(fila_bloqueados));
					}

				}
			}

			inicio_simulacao = clock();

		}


		if(fila_3->inicio==NULL && fila_4->inicio==NULL){
			fila_prioridade = 2;
		}

		while(fila_2->inicio!=NULL && fila_prioridade==2 && inicio_simulacao<fim_simulacao){
			Thread* executa = removerFila(fila_2);
			inicio_thread_time = clock();

			fim_thread_time = inicio_thread_time + (CLOCKS_PER_SEC*0.001)*(long)quantum;

			while(inicio_thread_time<fim_thread_time){
		
				pthread_mutex_lock(&executa->mutex);
				pthread_cond_signal(&executa->permissao);
				inicio_thread_time = clock();
				pthread_mutex_unlock(&executa->mutex);

			}
			if(executa->estado==2 || inicio_simulacao>fim_simulacao){
				addFila(fila_bloqueados, executa);
				executa->clock_saida = clock();
				executa->clock_retorno = executa->clock_saida + (CLOCKS_PER_SEC*0.001)*(long)executa->tempo_ES;
			}else{
				addFila(fila_2, executa);
			}

			if(fila_bloqueados->inicio != NULL){
				fila_bloqueados->inicio->clock_saida = clock();
				if(fila_bloqueados->inicio->prioridade>=fila_prioridade
				 && fila_bloqueados->inicio->clock_saida>fila_bloqueados->inicio->clock_retorno){

					fila_prioridade = fila_bloqueados->inicio->prioridade;

					if(fila_bloqueados->inicio->prioridade==4){
						addFila(fila_4, removerFila(fila_bloqueados));
					}else if(fila_bloqueados->inicio->prioridade==3){
						addFila(fila_3, removerFila(fila_bloqueados));
					}else if(fila_bloqueados->inicio->prioridade==2){
						addFila(fila_2, removerFila(fila_bloqueados));
					}else if(fila_bloqueados->inicio->prioridade==1){
						addFila(fila_1, removerFila(fila_bloqueados));
					}

				}
			}

			inicio_simulacao = clock();

		}


		if(fila_3->inicio==NULL && fila_4->inicio==NULL && fila_2->inicio == NULL){
			fila_prioridade = 1;
		}


		while(fila_1->inicio!=NULL && fila_prioridade==1 && inicio_simulacao<fim_simulacao){
			Thread* executa = removerFila(fila_1);
			inicio_thread_time = clock();

			fim_thread_time = inicio_thread_time + (CLOCKS_PER_SEC*0.001)*(long)quantum;

			while(inicio_thread_time<fim_thread_time){
		
				pthread_mutex_lock(&executa->mutex);
				pthread_cond_signal(&executa->permissao);
				inicio_thread_time = clock();
				pthread_mutex_unlock(&executa->mutex);

			}
			if(executa->estado==2 || inicio_simulacao>fim_simulacao){
				addFila(fila_bloqueados, executa);
				executa->clock_saida = clock();
				executa->clock_retorno = executa->clock_saida + (CLOCKS_PER_SEC*0.001)*(long)executa->tempo_ES;
			}else{
				addFila(fila_1, executa);
			}

			if(fila_bloqueados->inicio != NULL){
				fila_bloqueados->inicio->clock_saida = clock();
				if(fila_bloqueados->inicio->prioridade>=fila_prioridade
				 && fila_bloqueados->inicio->clock_saida>fila_bloqueados->inicio->clock_retorno){

					fila_prioridade = fila_bloqueados->inicio->prioridade;

					if(fila_bloqueados->inicio->prioridade==4){
						addFila(fila_4, removerFila(fila_bloqueados));
					}else if(fila_bloqueados->inicio->prioridade==3){
						addFila(fila_3, removerFila(fila_bloqueados));
					}else if(fila_bloqueados->inicio->prioridade==2){
						addFila(fila_2, removerFila(fila_bloqueados));
					}else if(fila_bloqueados->inicio->prioridade==1){
						addFila(fila_1, removerFila(fila_bloqueados));
					}

				}
			}

			inicio_simulacao = clock();

		}


		inicio_simulacao = clock();
		// printf("endd\n");

	}

	while(fila_bloqueados->inicio != NULL){
		Thread* finaliza = removerFila(fila_bloqueados);
		finaliza->estado = 3;
		pthread_cond_signal(&finaliza->permissao);

	}

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

	// lê o número de threads a serem criadas
	printf("Digite o numero de threads\n");
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
	fila_prioridade = 1;

	// lê a prioridade de cada thread no vetor
	printf("Digite a prioridade de cada thread\n");
	for(int i=0;i<num_threads;i++){
		scanf("%d", &thread_structs[i].prioridade);
		if(thread_structs[i].prioridade>fila_prioridade){
			fila_prioridade = thread_structs[i].prioridade;
		}
	}

	// lê o numero de instruções que cada thread executa
	printf("Digite o numero de instrucoes que cada thread executa antes de pedir E/S\n");
	for(int i=0;i<num_threads;i++){
		scanf("%d", &thread_structs[i].num_instrucoes);
	}

	// lê o tempo de E/S de cada thread
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
	printf("Digite o tempo da simulacao(ms)\n");
	scanf("%d", &tempo_sim);

	// marca o inicio da simulação
	inicio_simulacao = clock();
	// marca quando ela deve acabar (tempo de simulação)
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
	for(int i=0;i<num_threads;i++){
		pthread_join(tids[i], NULL);

	}

	// espera pelo escalonador
	pthread_join(escalonador_tid, NULL);
	printf("the end\n");

	return 0;
}