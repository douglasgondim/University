
/*FAÇA UM ALGORITMO QUE PREENCHA UMA MATRIZ 5X5 DE INTEIROS
 * a) a soma dos números ímpares fornecidos
 * b) a soma de cada uma das 5 colunas
 * c) a soma de cada uma das 5 linhas
 *  
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
	int aux=0;
	for(int i=0; i < TAM; i++){
		for (int j=0; j < TAM; j++){
			//COM IF
			//if(matriz[i][j]%2!=0){
			//	aux += matriz[i][j];
			//}
			//COM OPERADOR TERNÁRIO
			//aux += (matriz[i][j]%2!=0) ? matriz[i][j] : 0;			
			aux += (matriz[i][j]%2 !=0)*matriz[i][j];
		}
	}
	printf("O valor dos ímpares fornecidos é: %d", aux);

	// b)
	int cont_col;
	for(int j=0; j < TAM; j++){
		cont_col = 0;
		for (int i=0; i < TAM; i++){
			cont_col += matriz[i][j];
		}
		printf("\n A soma da coluna %d eh: %d", j, cont_col);
	}
	
	int cont_lin;
	for(int i=0; i < TAM; i++){
		cont_lin = 0;
		for (int j=0; j < TAM; j++){
			cont_lin += matriz[i][j];
		}
		printf("\n A soma da linha %d eh: %d", i, cont_lin);
	}	
	
	
	return 0;
}
