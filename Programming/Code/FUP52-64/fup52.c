//Alocacao dinamica
#include <stdio.h>
#include <stdlib.h>

int main(){
	int n, *vetor;
	scanf("%d", &n);
	vetor = (int *) malloc(sizeof(int)*n);
	if (vetor == NULL){
		printf("falha na alocacao");
	}
	else{
		printf("vetor alocado");
	}
	free(vetor);

	
	
	return 0;
}
