#include <stdio.h>
#include <stdlib.h>
//alocacao de matriz

int main(){
	int **matriz;
	
	matriz = (int **) malloc(5*sizeof(int *));
	for(int i = 0; i <5; i++){
		matriz[i] = (int *) malloc(5*sizeof(int));
	}
	//carrega os dados da matriz
	int contador=0;
	for(int i =0; i <5; i++){
		for(int j =0; j <5; j++){
			matriz[i][j] = ++contador;
		}
	}
	//imprime
	for(int i =0; i <5; i++){
		for(int j =0; j <5; j++){
			printf("\t%d",matriz[i][j]);
		}
		printf("\n");
	}
	
	//liberar memoria
	for(int i =0; i < 5; i++){
		free(matriz[i]);
	}
	free(matriz);
	
	return 0;
}
