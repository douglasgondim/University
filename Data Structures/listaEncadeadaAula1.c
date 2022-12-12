#include <stdio.h>
#include <stdlib.h>

#include "no.h"

NO *inicio;
NO *fim;
int tam = 0;

void addInicio(int elemento){

	NO *novo = malloc (sizeof(NO));
	novo->elemento = elemento;
	novo->prox = NULL;
	if(tam == 0){ //inicio == null
	 fim = novo;
	}else{
	 novo->prox = inicio;	 
	}
	inicio = novo;
	tam++;
}

//addfim...

void addFim(int elemento){
	NO *novo = malloc(sizeof(NO));
	novo->elemento = elemento;
	novo->prox = NULL;
	if(tam==0){
		inicio = novo;
	}else{
		fim->prox = novo;
	}
	fim = novo;
	tam++;
}

//add posicao...

void addPosicao(int posicao, int elemento){
	int i;
	NO *aux = inicio;
	NO *novo = malloc(sizeof(NO));
	novo->elemento = elemento;
	novo->prox = NULL;
	if(posicao>=0 && posicao<=tam){
		if(tam==0){
			inicio = novo;
			fim = novo;
		}else{
			if(posicao==0){
				novo->prox = inicio;
				inicio = novo;
			}else{
				for(i=0;i<posicao-1;i++){
					aux = aux->prox;
				}
				novo->prox = aux->prox;
				aux->prox = novo;
			}
		}
		tam++;
	}
}





void imprime () {
   NO *aux;
   for (aux = inicio; aux != NULL; aux = aux->prox) 
      printf ("%d\n", aux->elemento);
}



void main(){

	
}
