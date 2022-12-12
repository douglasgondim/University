// Faça um programa que crie um vetor N de 5 posições 
// e o preencha com numeros de 1 ate 10 e depois imprima esse vetor

#include <stdio.h>
int main(){
	int N[10];

	for(int i=0;i<5;i++){
		scanf("%d", &N[i]);
	}


	for(int i=0;i<5;i++){
		printf("%d", N[i]);
	}

	return 0;
}