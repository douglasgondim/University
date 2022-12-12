/* 

3-) Crie uma matriz n x m, leia os valores para essa matriz, 
depois inverta os valores na vertical. (Use alocação dinâmica)

*/

#include <stdio.h>
#include <stdlib.h>
int main(){
	int **matrix, a, b;
	scanf("%d %d", &a, &b);
	matrix = (int**) malloc(sizeof(int*)*a);
	for (int i=0; i<a; i++){
		matrix[i] = (int*) malloc(sizeof(int)*b);
	}

	for (int i=0; i<a; i++){
		for (int j=0; j<b; j++){
			scanf("%d", &matrix[i][j]);
		}
	}

	for (int i=0; i<a; i++){
		for (int j=0; j<b; j++){
			printf("%5d", matrix[i][j]);
		}
		printf("\n");
	}
	
	
	// for (int i=0; i<a; i++){
	// 	for (int j=0; j<b; j++){
	// 		scanf("%d", &matrix[i][j]);
	// 	}
	// }
	// for (int i=0; i<a; i++){
	// 	for (int j=0; j<b; j++){
	// 		printf("%.5d", matrix[i][j] );
	// 	}
	// 	printf("\n");
	// }

	

	return 0;
}