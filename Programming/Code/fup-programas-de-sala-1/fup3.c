
#include <stdio.h>

//coloca em ordem crescente tres numeros distintos

int main(){
	int a,b,c;
	int menor, meio, maior; //armazena a ordem
	scanf("%d %d %d", &a, &b, &c);
	
	if(a > b){
		maior = a;
		menor = b;
	}else{
		maior = b;
		menor = a;
	}
	if(c > maior){
		meio = maior;
		maior = c;
	}else{
		if( c < menor){
			meio = menor;
			menor = c;
		}
		else{
			meio = c;
		}
	}
	printf("a ordem é: %d %d %d", menor, meio, maior);
	
	
	return 0;
}
