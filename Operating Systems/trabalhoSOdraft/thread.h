/* 	José Douglas Gondim Soares MAT 416753
	Fernanda Costa de Sousa    MAT 411684 
*/


// 												estrutura thread
/* 
	cada thread tem um semáforo mutex, uma variavel condicional de permissão, um número único, um estado de execução
	uma prioridade, um número de instruções a executar, tempo de entrada/saída, clock de saída que marca o tempo
	exato que a thread foi para bloqueado, um tempo de retorno que calcula o tempo queela deve retornar par o 
	estado de pronto e um ponteiro prox para a criação de filas de threads.

*/

struct thread{
	pthread_mutex_t mutex;
	pthread_cond_t  permissao;
	int thread_num;
	int estado; //0 == executando, 1== pronto, 2 == bloqueado
	int prioridade;
	int num_instrucoes;
	int tempo_ES;
	time_t clock_saida;
	time_t clock_retorno;
	struct thread* prox;
};
typedef struct thread Thread;
