

#include <stdio.h>
#include <stdlib.h>

int main(){
	int **matriz, *p;
	int contador = 0;
	matriz = (int **)malloc(sizeof(int *)*5);
	//aloca
	for(int i =0; i < 5; i++){
		matriz[i] = (int *) malloc(sizeof(int)*5);
	}
	
	for(int i =0; i < 5; i++){
		for(int j=0; j < 5; j++){
			matriz[i][j] = ++contador;
		}
	}
	//matriz[i][j] == *(*(matriz+i)+j)
	p->*matriz;
	printf("%d", *p);
	
	//desaloca
	for(int i =0; i < 5; i++){
		free(matriz[i]);
	}
	free(matriz);
	
	

	return 0;
}
