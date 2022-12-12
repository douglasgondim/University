
#include <stdio.h>

int main(){
	
	int matriz[3][3];
	
	//atribuir a uma posição da matriz
	matriz[0][0] = 1;
	matriz[2][1] = 11;
	printf("%d\n", matriz[0][0]);
	printf("%d\n", matriz[2][1]);
	
	printf("CARREGANDO MATRIZ USANDO FOR:\n");
	for(int i=0; i < 3; i++){
		for(int j=0; j < 3; j++){
			printf("digite a posição [%d %d] :\n", i, j);
			scanf("%d", &matriz[i][j]);			
		}
	}
	
	//IMPRIME A MATRIZ TODA
	printf("A MATRIZ COMPLETA \n");
	for(int i=0; i < 3; i++){
		for(int j=0; j < 3; j++){
			printf("%5d ", matriz[i][j]);
		}
		printf("\n");
	}	
	
	
	return 0;
}
