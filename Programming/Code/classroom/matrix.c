#include <stdio.h>
#define N 100
int main(){
	int matrix_1[N][N], matrix_2[N][N], matrix_3[N][N], n;
	scanf("%d", &n);

	if (n > N){
		printf("Value too high!\n");
		return 0;
	}

	printf("Enter first matrix: \n");
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			printf("Position [%d][%d]: ", i,j);
			scanf("%d", &matrix_1[i][j]);
		}
	}

	printf("\nEnter second matrix: \n");
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			printf("Position [%d][%d]: ", i,j);
			scanf("%d", &matrix_2[i][j]);
		}
	}

	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			matrix_3[i][j] = 0;
			for (int k=0; k<n; k++){
				matrix_3[i][j] += matrix_1[i][k] * matrix_2[k][j];
			}
		}
	}

	printf("\nMatrix 3 \n\n");
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			printf("%5d", matrix_3[i][j]);
		}
		printf("\n");
	}



	return 0;
}