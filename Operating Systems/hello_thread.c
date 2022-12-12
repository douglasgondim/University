#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NumThreads 10
//imprime a id do thread e sai
void *print_hello_word(void *tid){
	printf("Ola mundo. Eu sou a Thread %d\n", tid);
	pthread_exit(NULL);
}

int main(int argc, char *argv[]){
//o programa principal cria 10 thread e sai
pthread_t threads[NumThreads];
int status,i;

	for (i = 0; i < NumThreads; i++){
		printf("Main falando. Criando Thread %d\n", i);
		status = pthread_create (&threads[i],NULL, print_hello_word, (void *)i);

		if (status != 0) {

			printf("Erro. Pthread_create retornou o codigo de erro %d\n",status);
			exit (-1);
		}
	}

	exit (NULL);
}