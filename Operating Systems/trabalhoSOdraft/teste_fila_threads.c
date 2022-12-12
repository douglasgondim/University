#include <stdio.h>
#include "fila_de_threads.h"

int main(){
	Fila* fila_1 = criarFila();
	Thread* thread1 = criarThread();
	Thread* thread2 = criarThread();
	Thread* thread3 = criarThread();
	thread1->prioridade = 3;
	thread2->prioridade = 4;
	thread3->prioridade = 1;


	addFila(fila_1, thread1);
	addFila(fila_1, thread2);
	addFila(fila_1, thread3);
	removerFila(fila_1);
	removerFila(fila_1);
	imprimir(fila_1);

	return 0;
}