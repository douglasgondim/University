
#include <stdio.h>
#include <stdlib.h>

int main(){
	int matriz_1[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	
	int **matriz_2 = (int **) malloc(3*sizeof(int *));
	for(int i=0; i <3; i++){
		matriz_2[i] = (int *) malloc(3*sizeof(int));
	}
	
	//carrega os dados da matriz
	int contador=0;
	for(int i =0; i <3; i++){
		for(int j =0; j <3; j++){
			matriz_2[i][j] = ++contador;
		}
	}	
	//matriz[i][j] = *(*(matriz+i)+j);
	
	printf("%d",*((*(matriz_2))+4));
	
	return 0;
}
