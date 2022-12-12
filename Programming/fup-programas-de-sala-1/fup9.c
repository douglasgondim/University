

//programa que calcula o MMC

#include <stdio.h>

int main(){
	int originalA, originalB;
	int a, b, aux, mmc, mdc;
	printf("Escreva os dois números");
	scanf("%d %d", &a, &b);	
	originalA = a;
	originalB = b;
	while(a % b != 0){
		aux=a%b;
		a=b;	
		b=aux;
	}	
	mdc = b;
	mmc = (originalA*originalB)/mdc;
	printf("O mmc é: %d",mmc);
	return 0;
}
