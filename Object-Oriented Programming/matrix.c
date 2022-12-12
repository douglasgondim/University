/*
	0   5   4   0   0   0
	5   0   50  10  0   0
	4   50  0   0   3   0
	0   0   0   0   2   7
	0   0   3   2   0   1
	0   0   0   7   1   0



*/

#include <stdio.h>
int main(){
	int i,j;
	int matrix[6][6];

	for(i=0;i<6;i++){
		for(j=0;j<6;j++){
			matrix[i][j] = 0;
		}
	}
	matrix[0][1] = 5;
	matrix[0][2] = 4;
	matrix[1][0] = 5;
	matrix[1][2] = 50;
	matrix[1][3] = 10;
	matrix[2][0] = 4;
	matrix[2][1] = 50;
	matrix[2][4] = 3;
	matrix[3][4] = 2;
	matrix[3][5] = 7;
	matrix[4][2] = 3;
	matrix[4][3] = 2;
	matrix[4][5] = 1;
	matrix[5][3] = 7;
	matrix[5][4] = 1;

	for(i=0;i<6;i++){
		for(j=0;j<6;j++){
			printf("%5d", matrix[i][j]);
		}
		printf("\n");
	}



	return 0;
}