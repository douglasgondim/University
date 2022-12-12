
/*FAÇA UM ALGORITMO QUE PREENCHA UMA MATRIZ NXN DE INTEIROS E IMPRIMA:
 * a) a diagonal principal
 * b) o triângulo superior à diagonal principal
 * c) o triângulo inferior à diagonal principal
 * d) a diagonal secundária
   e) o triângulo superior a diagonal secundaria
   f) o triângulo inferior à diagonal secundária.
 
*/


#include <stdio.h>
#define TAM 3

int main(){
	int matriz[TAM][TAM];
	
	for(int i=0; i < TAM; i++){
		for (int j=0; j < TAM; j++){
			printf("\nDigita a posição [%d, %d]: ", i,j);
			scanf("%d", &matriz[i][j]);
		}
	}
	//a)
	printf("Elementos da diagonal principal: ");
	for(int i=0; i < TAM; i++){
		 printf("%d ", matriz[i][i]);
	}	
	printf("\n");
	//b)
	printf("Elementos do triangulo superior a diagonal principal: ");
	for(int i=0; i < TAM; i++){
		for (int j=0; j < TAM; j++){
			if(j > i){
				printf("%d ",matriz[i][j]);
				}
		}
	}
	printf("\n");
	//c)
	printf("Elementos do triangulo inferior a diagonal principal: ");
	for(int i=0; i < TAM; i++){
		for (int j=0; j < TAM; j++){
			if(j < i){
				printf("%d ",matriz[i][j]);
				}
		}
	}
	printf("\n");
	//d)
	printf("Elemento da diagonal secundária: ");
	for(int i=0; i < TAM; i++){
		printf("%d ", matriz[i][TAM - 1 - i]);
	}
	
	

	return 0;
}
