


//programa que calcula o MMC

#include <stdio.h>

int calculaMDC(int a, int b){
	int aux;
	while(a % b != 0){
		aux=a%b;
		a=b;	
		b=aux;
	}	
	return b;
}

int main(){
	int a, b, mmc, mdc;
	printf("Escreva os dois números");
	scanf("%d %d", &a, &b);	
	mdc = calculaMDC(a,b);
	mmc = (a*b)/mdc;
	printf("O mmc é: %d",mmc);
	return 0;
}
