
//Programa que calcula o MDC

#include <stdio.h>

/*
Para fazer comentarios
em várias linhas 
*/

int i; 

int main(){
	int mdc, n1, n2; //mdc e numeros de entrada
//	int i; // variável de controle
	printf("Informe os números: ");
	scanf("%d %d", &n1, &n2); //le os inteiros
	mdc = 1;
	
	for(int i=1; i <= n1; i++){
		//% representa mod
		//&& representa e (lógico)
		if(n1 % i == 0 && n2 % i == 0){
			mdc = i;
		}
	}

	printf("O MDC é: %d", mdc);
	
	
	
	return 0;
}
