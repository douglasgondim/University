#include <stdio.h>
#include <stdlib.h>
int main(){
	int **matrix, a;
	scanf("%d", &a);

	matrix = (int**) malloc(a*sizeof(int*));
	for(int i=0; i<a; i++){
		matrix[i] = (int*) malloc(a*sizeof(int));
	}

	for(int i=0; i<a; i++){
		for(int j=0; j<a; j++){
			scanf("%d", &matrix[i][j]);
		}
	}

	for(int i=0; i<a; i++){
		for(int j=0; j<a; j++){
			printf("%5d", matrix[i][j]);
		}
		printf("\n");
	}

	for(i=0; i<a; i++){
		free(matrix[i]);
	}
	free(matrix);



	return 0;
}