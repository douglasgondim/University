
//IMPLEMENTAR ALGORITMO DE EUCLIDES
#include <stdio.h>
int main(){
	int a, b, aux;
	// mdc = a/b; //supondo mdc declarado inteiro
	// mdc = (int) a/b; //supondo mdc declarado float
	printf("Escreva os dois números");
	scanf("%d %d", &a, &b);	
	while(a % b != 0){
		aux=a%b;
		a=b;	
		b=aux;
	}	
	printf("O mdc é: %d",b);
	return 0;
}

