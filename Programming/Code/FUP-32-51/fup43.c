
#include <stdio.h>

int main(){
	int M[3][4] = {{1,2,5,7},{8,3,9,10},{8,5,9,11}}; //DECLARANDO UMA MATRIZ 3X4
	
	//i indice da linha
	for(int i=0; i < 3; i++){
		for(int j=0; j < 4; j++){
			printf("\ndigite o valor da posicao: %d %d: ",i,j);
			scanf("%d", &M[i][j]);
		}
	}
	printf("%d", M[1][2]);
	
	return 0;
}

