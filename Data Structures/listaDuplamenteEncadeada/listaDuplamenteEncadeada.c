// José Douglas Gondim Soares MAT 416753

#include <stdio.h>
#include <stdlib.h>
#include "no.h"

no* inicio;
no* fim;
int tam = 0;

void addInicio(int elemento){
	no* novo = malloc(sizeof(no));
	novo->elemento = elemento;
	novo->prox = NULL;
	novo->ant = NULL;

	if(tam==0){
		fim = novo;
	}else{
		novo->prox = inicio;
		inicio->ant = novo;
	}
	inicio = novo;
	tam++;

}

void addFim(int elemento){
	no* novo = malloc(sizeof(no));
	novo->elemento = elemento;
	novo->prox = NULL;
	novo->ant = NULL;

	if(tam==0){
		inicio = novo;
	}else{
		novo->ant = fim;
		fim->prox = novo;
	}
	fim = novo;
	tam++;

}

void addPosicao(int posicao, int elemento){
	if(posicao>=0 && posicao <=tam && tam>0){
		if(posicao==0) addInicio(elemento);
		else if(posicao==tam) addFim(elemento);
		else{
			no* novo = malloc(sizeof(no));
			novo->elemento = elemento;
			novo->prox = NULL;
			novo->ant = NULL;

			if(posicao < (int)tam/2){
				no*aux = inicio;
				int i;
				for(i=0;i<posicao-1;i++){
					aux = aux->prox;
				}
				novo->prox = aux->prox;
				novo->ant = aux;
				aux->prox->ant = novo;
				aux->prox = novo;
			}else{
				no* aux = fim;
				int i;
				for(i=tam; i>posicao+1;i--){
					aux = aux->ant;

				}
				novo->prox = aux;
				novo->ant = aux->ant;
				aux->ant->prox = novo;
				aux->ant = novo;
			}
			tam++;
		}

	}
}

void rmInicio(){
	if(tam>0){
		no* lixo = inicio;
		if(tam==1){
			inicio = NULL;
			fim =  NULL;
		}else{
			inicio = inicio->prox;
			inicio->ant = NULL;
		}
		free(lixo);
		tam--;
	}
}

void rmFim(){
	if(tam>0){
		no* lixo = fim;
		if(tam==1){
			inicio = NULL;
			fim = NULL;
		}else{
			fim = fim->ant;
			fim->prox = NULL;
		}
		free(lixo);
		tam--;
	}
}

void rmPosicao(int posicao){
	if(posicao>=0 && posicao<tam && tam>0){
		if(posicao==0) rmInicio();
		else if(posicao==tam-1) rmFim();
		else{
			int i;
			if(posicao < (int)tam/2){
				no* aux = inicio;
				for(i=0;i<posicao-1;i++){
					aux = aux->prox;
				}
				no* lixo = aux->prox;
				aux->prox->prox->ant = aux;
				aux->prox = aux->prox->prox;
				free(lixo);
			}else{
				no *aux = fim;
				for(i=tam-1; i>posicao+1;i--){
					aux = aux->ant;
				}
				no* lixo = aux->ant;
				aux->ant->ant->prox = aux;
				aux->ant = aux->ant->ant;
				free(lixo);
			}		
		tam--;
		}
	}

}


void imprime(){
	int i;
	no* aux = inicio;
	for(i=0;i<tam;i++){
		printf("%d\n", aux->elemento);
		aux = aux->prox;
	}
}



int main(){
	addPosicao(0, 1);


	return 0;
}