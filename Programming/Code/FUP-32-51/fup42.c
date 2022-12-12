#include <stdio.h>
#include <stdlib.h>


int main(){
	static int m[10000][10000];	
	//alocacao de vetor de 5 posicoes;
	int *vetor = (int *) malloc(5*sizeof(int));

	for (int i =0; i <5; i++){
		vetor[i] = i+1;
	}

	vetor = (int *) realloc(vetor, 10*sizeof(int));

	for (int i =0; i <10; i++){
		printf("%d ", vetor[i]);
	}	
	
	free(vetor);
	
	
	return 0;
}
