/* 

3-) Crie uma matriz n x m, leia os valores para essa matriz, 
depois inverta os valores na vertical. (Use alocação dinâmica)

*/

#include <stdio.h>
#include <stdlib.h>
int main(){
	int **matrix, n, m, aux;
	scanf("%d %d", &n, &m);
	matrix = (int**) malloc(sizeof(int*)*n);
	for (int i=0; i<n; i++){
		matrix[i] = (int*) malloc(sizeof(int)*m);
	}

	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			scanf("%d", &matrix[i][j]);
		}
	}



	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			printf("%5d", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	for (int j=0; j<m; j++){
		for (int i=0; i<n/2; i++){
			aux = matrix[i][j];
			matrix[i][j] = matrix[n-1-i][j];
			matrix[n-1-i][j] = aux;
		}
	}


	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			printf("%5d", matrix[i][j]);
		}
		printf("\n");
	}



	return 0;
}