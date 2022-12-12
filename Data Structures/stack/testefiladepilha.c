#include <stdio.h>
#include <stdlib.h>
#include "filadepilha.h"

int main(){
	Pilha* pilha1 = criar_pilha();
	Pilha* pilha2 = criar_pilha();
	Pilha* pilha3 = criar_pilha();
	Pilha* pilha4 = criar_pilha();
	Pilha* pilha5 = criar_pilha();

	adicionar_pilha(pilha1,5);
	adicionar_pilha(pilha2,5);
	adicionar_pilha(pilha3,5);
	adicionar_pilha(pilha4,5);
	adicionar_pilha(pilha5,5);
	adicionar_pilha(pilha1,2);
	adicionar_pilha(pilha3,7);
	adicionar_pilha(pilha4,9);
	adicionar_pilha(pilha4,10);

	Fila* fila = criar_fila();

	adicionar_fila(fila,pilha1);
	adicionar_fila(fila,pilha2);
	adicionar_fila(fila,pilha3);
	adicionar_fila(fila,pilha4);
	adicionar_fila(fila,pilha5);
	
	imprimir_fila(fila);

	return 0;	
}