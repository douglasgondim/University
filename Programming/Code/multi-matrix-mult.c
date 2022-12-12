// reads and multiplies matrices

#include <stdio.h>
#define N 3
int main(){
	int matrix_1[N][N], matrix_2[N][N], matrix_3[N][N];

	for (int i=0; i<3; i++){
		for (int j=0; j<3; j++){
			printf("Enter position [%d, %d]\n", i,j);
			scanf("%d", matrix_1[i][j])
		}
	}




	return 0;
}