#include <stdio.h>
#include <stdlib.h>


int vetor[10];
int tam = 0;

void add(int posicao, int elemento){

	if(posicao >= 0 && posicao <= tam && tam < 10){
	 int i;
		for(i = tam; i > posicao; i--){
			vetor[i] = vetor[i-1];
		}
	 vetor[posicao]= elemento;
	 tam++;
	}
}

int remover(int posicao){
	int aux;
	if(tam>0){
		if(posicao>=0 && posicao<tam){
			aux = vetor[posicao];
			for(int i=posicao;i<tam-1;i++){
				vetor[i] = vetor[i+1];
			}
			tam--;
			return aux;
		}	
	}
	printf("\nPosicao Invalida\n");
	return -1;
}

void imprimir(){
	int i;
	printf("imprimindo... \n");
	for(i = 0; i < tam; i++){
		printf("%d ", vetor[i]);
	}
}


void main(){

	add(0,10); //add inicio
	add(1,20); //add fim
	add(1,30); //add "meio"
	imprimir();
}
