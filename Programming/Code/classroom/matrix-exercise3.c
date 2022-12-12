/*2) Elabore um algorítmo que preencha uma matriz 5x5 e depois:

	a) Trocar a segunda e a quinta linha.
	b) Trocar a primeira e a quarta coluna.
	c) Trocar a diagonal principal e a secundária.
	d) Escreva como a Matriz ficou.
	*/

#include <stdio.h>
#define N 5
int main(){
	int matrix_1[N][N], auxMatrix[N][N];
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			printf("Enter Position: [%d][%d]: ", i,j);
			scanf("%d", &matrix_1[i][j]);
		}
	}

	printf("\nMatrix\n");
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			printf("%5d", matrix_1[i][j]);
		}
		printf("\n");
	} 

	for (int j=0; j<N; j++){
		auxMatrix[1][j] = matrix_1[1][j];
		auxMatrix[4][j] = matrix_1[4][j];
		matrix_1[1][j] = auxMatrix[4][j];
		matrix_1[4][j] = auxMatrix[1][j]; 
	}
	printf("\nMatrix\n");
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			printf("%5d", matrix_1[i][j]);
		}
		printf("\n");
	}

	for (int j=0; j<N; j++){
		auxMatrix[j][0] = matrix_1[j][0];
		auxMatrix[j][3] = matrix_1[j][3];
		matrix_1[j][0] = auxMatrix[j][3];
		matrix_1[j][3] = auxMatrix[j][0]; 
	}
	printf("\nMatrix\n");
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			printf("%5d", matrix_1[i][j]);
		}
		printf("\n");
	} 


	return 0;
}