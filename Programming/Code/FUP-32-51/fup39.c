#include <stdio.h>
#include <stdlib.h>

//ALOCAÇÃO DINÂMICA
//PROGRAMA QUE DADO N INTEIROS FORNECIDOS PELO USUARIO
//O PROGRAMA ORDENA OS N INTEIROS
int main(){
	int tam,aux;
	printf("Digite a quantidade de números para ordenar: ");
	scanf("%d", &tam);
	
	//alocacao
	int *v = (int *) malloc(tam*sizeof(int)); //alocacao
	
	//informa valores
	for (int i=0; i < tam; i++){
		scanf("%d", &v[i]);
	}
	//ordenação por BOLHA
	for(int i=1; i < tam; i++){
		for (int j=0; j < tam - i; j++){
			if(v[j] > v[j+1]){
				aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;
			}
		}
	}
	
	//informa valores
	printf("\n");
	for (int i=0; i < tam; i++){
		printf("%d ", v[i]);
	}		
	
	//libera memoria
	free(v);
	
	return 0;
}
