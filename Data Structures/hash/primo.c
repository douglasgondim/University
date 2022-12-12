#include <stdio.h>

int ehPrimo(int num){
	int i=1;
	int divisores=0;
	while(i<=num){
		if(num % i ==0){
			divisores++;
		}
		i++;
	}
	if(divisores ==2){
		return 1;
	}
	return 0;
}


int main(){
	int numero;
	scanf("%d", &numero);
	numero++;
	while(ehPrimo(numero) != 1){
		numero++;
	}
	printf("%d\n", numero);


	return 0;
}