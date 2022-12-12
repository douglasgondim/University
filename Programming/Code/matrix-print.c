#include <stdio.h>
int main(){
	int matrix[3][3] = {{1,2,1}, {1,1,1}, {1,3,1}};

	for (int i=0; i<3; i++){
		for (int j=0; j<3; j++){
			printf("%5d ", matrix[i][j]);
		}
		printf("\n");
	}

	return 0;
}