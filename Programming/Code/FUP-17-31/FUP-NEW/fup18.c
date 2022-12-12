
//ORDENAR UM VETOR
//ALGORITMO DA BOLHA

#include <stdio.h>

#define QTD 10

int main(){
	int valores[QTD],aux;
	
	for(int i=0; i < QTD; i++){
		scanf("%d", &valores[i]);
	}
	
	for(int j=QTD-1; j > 0; j--){
		for(int i=0; i < j; i++){
			if(valores[i] > valores[i+1]){
				aux = valores[i];
				valores[i] = valores[i+1];
				valores[i+1] = aux;
			}   
		}
	}


	for(int i=0; i < QTD; i++){
		printf("%d ", valores[i]);
	}
		
	
	return 0;
}
