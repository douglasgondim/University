
/*FAÇA UM ALGORITMO QUE PREENCHA UMA MATRIZ NXN DE INTEIROS E IMPRIMA:
 * a) a diagonal principal
 * b) o triângulo superior à diagonal principal
 * c) o triângulo inferior à diagonal principal
 * d) a diagonal secundária
 * 
 *  
*/

#include <stdio.h>
#define N 3
int main(){
	int matrix[N][N];

	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			printf("Enter position: [%d][%d]: ", i,j);
			scanf("%d", &matrix[i][j]);
		}
	}

	printf("\nMatrix\n");
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			printf("%5d", matrix[i][j]);
		}
		printf("\n");
	}


	printf("\nMain diagonal: \n");
	for (int i=0; i<N; i++){
		printf("%d ", matrix[i][i]);
				
	}

	printf("\nSuperior triangle: \n");
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			if(j>i){
				printf("%d ", matrix[i][j]);
			}

		}
	}

	printf("\nInferior triangle: \n");
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			if(i>j){
				printf("%d ", matrix[i][j]);
			}
		}
	}

	printf("\nSecondary diagonal: \n");
	for (int i=0; i<N; i++){
		printf("%d ", matrix[i][N-1-i]);
	}

	printf("\nSecondary superior triangle: \n");
	for(int i=0; i<N; i++){
		for(int j=0; j<N - i - 1; j++){
			printf("%d ", matrix[i][j]);
		}
	}

printf("\nSecondary inferior triangle: \n");
	for(int i=0; i<N; i++){
		for(int j=0; j>N - i - 1; j++){
			printf("%d ", matrix[i][j]);
		}
	}




	return 0;
}
