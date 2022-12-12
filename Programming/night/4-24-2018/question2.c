/* 2. Leia um número fornecido pelo usuário. 
	Se esse número for positivo, calcule a raiz quadrada do número. 
	Se o número for negativo, mostre uma mensagem dizendo que o número é inválido. */

#include <stdio.h>
#include <math.h>
int main(){
	float n;
	scanf("%f", &n);
	if (n>0){
		printf("%.2f", sqrt(n));
	}else{
		printf("Invalid Number");
	}
	

	return 0;
}