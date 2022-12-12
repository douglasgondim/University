
#include <stdio.h>

//construa uma funcao que calcula o fatorial de um numero

//n! = 1 x 2 x 3 x... x n
//retorna o fatorial de a
int fatorial (int a){
    int aux=1;
    for(int i=1;i<=a;i++){
		aux=aux*i;
	}
	return aux;
}

int fatorialRecursivo (int a){
	return (a == 0 || a == 1) ? 1 : fatorialRecursivo(a-1)*a;
}

int main(){
	int n, result;
	scanf("%d", &n);
	result = fatorialRecursivo(n);
	printf("%d", result);
	
	
	return 0;
}
