#include <stdio.h>
#include <stdlib.h>
int main(){
	char enemy[5][10] = {{0,0,1,0,0,1,1,0,1,1}, {1,0,0,1,1,0,1,0,0,1},
						 {0,1,0,1,0,1,0,1,0,1}, {1,1,0,0,0,1,1,0,0,0},
						 {0,0,0,0,1,1,1,0,1,0}};

	char board[5][10];
	int i, j;

	for(int i=0; i<5; i++){
		for(int j=0; j<10; j++){
			board[i][j] = '.';
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
	printf("Enter shot coordinates (line/col): ");
	scanf("%d %d", &i, &j);

	while(i>-1 && j>-1){
		if(enemy[i][j]==1){
			board[i][j]='x';
		}else{
			board[i][j] = '0';
		}
	}

	for(int i=0; i<5; i++){
		for(int j=0; j<10; j++){
			printf("%c", board[i][j]);
		}
		printf("\n");
	}

	printf("Enter coordinates (line/col): ");
	scanf("%d %d", &i, &j);

	return 0;
}