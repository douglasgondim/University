// José Douglas Gondim Soares MAT 416753

#include <stdio.h>
#include <stdlib.h>

struct no{
	int elemento;
	struct no* prox;
	struct no* ant;

};

typedef struct no no;


no* inicio;
int tam = 0;

void addInicio(int elemento){
	no* novo = malloc(sizeof(no));
	novo->elemento = elemento;
	novo->prox = NULL;
	novo->ant = NULL;

	if(tam==0){
		inicio=novo;
		novo->prox = inicio;
		novo->ant = inicio;
	}else{
		novo->prox = inicio;
		novo->ant = inicio->ant;
		inicio->ant->prox = novo;
		inicio-> ant  = novo;
		inicio=novo;
	}
	tam++;

}

void addFim(int elemento){
	no* novo = malloc(sizeof(no));
	novo->elemento = elemento;
	novo->prox = NULL;
	novo->ant = NULL;

	if(tam==0){
		inicio = novo;
		novo->prox = inicio;
		novo->ant = inicio;
	}else{
		novo->prox = inicio;
		novo->ant = inicio->ant;
		inicio->ant->prox = novo;
		inicio-> ant  = novo;
	}

	tam++;

}

void addPosicao(int posicao, int elemento){
	if(posicao>=0 && posicao <=tam){
		if(posicao==0) addInicio(elemento);
		else if(posicao==tam) addFim(elemento);
		else{
			no* novo = malloc(sizeof(no));
			novo->elemento = elemento;
			novo->prox = NULL;
			novo->ant = NULL;

			no* aux = inicio;
			int i;
			for(i=0;i<posicao-1;i++){
				aux = aux->prox;
			}

			novo->prox = aux->prox;
			novo->ant = aux;
			aux->prox->ant = novo;
			aux->prox = novo;
			tam++;
		}

	}
}

void rmInicio(){
	if(tam>0){
		no* lixo = inicio;
		if(tam==1){
			inicio = NULL;
		}else{
			inicio->ant->prox = inicio->prox;
			inicio->prox->ant = inicio->ant;
			inicio = inicio->prox;
		}
		free(lixo);
		tam--;
	}
}

void rmFim(){
	if(tam>0){
		no* lixo = inicio->ant;
		if(tam==1){
			inicio = NULL;
		}else{
			inicio->ant->ant->prox = inicio;
			inicio->ant = inicio->ant->ant;
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
			no* aux = inicio;
			int i;
			for(i=0;i<posicao-1;i++){
				aux = aux->prox;
			}
			no* lixo = aux->prox;
			aux->prox->prox->ant = aux;
			aux->prox = aux->prox->prox;
			free(lixo);
			tam--;
		}
			
	}

}

int sum(no* aux){
	if(aux->prox != inicio){
		return aux->prox->elemento + sum(aux->prox);
	}else{
		return inicio->elemento;
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

int tam_lista(){
	return tam;
}



int main(){
	addInicio(2);
	addInicio(4);
	addInicio(8);
	addInicio(2);
	imprime();
	printf("%d\n", sum(inicio));


	return 0;
}

/*
9-b)

addInicio  --> CONSTANTE
addFim     --> CONSTANTE
addPOsicao --> LINEAR
rmInicio   --> CONSTANTE
rmFim      --> CONSTANTE
rmPosicao  --> LINEAR

*/