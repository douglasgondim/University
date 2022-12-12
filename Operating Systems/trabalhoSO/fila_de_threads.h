/* 	José Douglas Gondim Soares MAT 416753
	Fernanda Costa de Sousa    MAT 411684 
*/

#include <stdio.h>
#include <stdlib.h>
#include "thread.h"

// Arquivo que constroi filas de threads, adiciona threads na fila e remove threads da fila

struct fila{
	Thread* inicio;
	Thread* fim;
	int tam;

};
typedef struct fila Fila;

Fila* criarFila(){
	Fila* nova_fila = malloc(sizeof(Fila));
	nova_fila->inicio = NULL;
	nova_fila->fim = NULL;
	nova_fila->tam=0;
	return nova_fila;
}


void addFila(Fila* fila, Thread* nova_thread){
	if(fila->tam==0){
		fila->inicio = nova_thread;
		fila->fim = nova_thread;
	}else{
		fila->fim->prox = nova_thread;
		fila->fim = nova_thread;
	}
	fila->tam++;
}

Thread* removerFila(Fila* fila){
	if(fila->tam>0){
		Thread* aux = fila->inicio;
		if(fila->tam==1){
			fila->inicio = NULL;
			fila->fim = NULL;
		}else{
			fila->inicio = fila->inicio->prox;
		}
		fila->tam--;
		return aux;
	}
	return NULL;
}
