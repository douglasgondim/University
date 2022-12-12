
/*FAÇA UM ALGORITMO QUE PREENCHA UMA MATRIZ 3X3 DE INTEIROS
 * a) a soma dos números ímpares fornecidos
 * b) a soma de cada uma das 5 colunas
 * c) a soma de cada uma das 5 linhas
 *  
*/

#include <stdio.h>
int main(){
	int matrix[3][3], sum;
	for (int i=0; i<3; i++){
		for (int j=0; j<3; j++){
			printf("Enter position [%d][%d]: ", i,j);
			scanf("%d", &matrix[i][j]);
		}
	}

	printf("\nMatrix: \n");
	for (int i=0; i<3; i++){
		for (int j=0; j<3; j++){
			printf("%5d", matrix[i][j]);
		}printf("\n");
	}


	sum =0;
	for (int i=0; i<3; i++){
		for (int j=0; j<3; j++){
			if (matrix[i][j]%2 != 0){
				sum += matrix[i][j];
			}
		}
	}

	printf("\nThe sum of all odd numbers in the matrix is: %d\n", sum);
	int column = 0;
	for (int i=0; i<3; i++){
		sum=0;
		for (int j=0; j<3; j++){
			sum += matrix[j][i];
		}
		column += 1;
		printf("\nSum of column %d\n", column);
		printf("%d", sum);
	}

	int line = 0;
	for (int i=0; i<3; i++){
		sum=0;
		for (int j=0; j<3; j++){
			sum += matrix[i][j];
		}
		line += 1;
		printf("\nSum of line %d\n", line);
		printf("%d", sum);
	}





	return 0;
}