/*

4-) Questão MAX ULTRA;
Aloque dinamicamente ma matriz N xN, depois inverta os valores na diagonal principal.

*/

#include <stdio.h>
#include <stdlib.h>
int main(){
	int **matrix, N, aux;
	scanf("%d", &N);
	matrix = (int**) malloc(sizeof(int*)*N);
	for (int i=0; i<N; i++){
		matrix[i] = (int*) malloc(sizeof(int)*N);
	}

	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			scanf("%d", &matrix[i][j]);
		}
	}

	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			printf("%5d", matrix[i][j]);
		}printf("\n");
	}

	printf("\n");


	for (int i=0; i<N/2; i++){
		aux = matrix[i][i];
		matrix[i][i] = matrix[N-1-i][N-1-i];
		matrix[N-1-i][N-1-i] = aux;
	}




	

	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			printf("%5d", matrix[i][j]);
		}printf("\n");
	}

	return 0;
}