#include <stdio.h>

//FUNÇÕES (CONTINUACAO)


int somaMaisUm(int a){
	a = a + 1;
	return a;
}

int somaMaisUmPonteiro(int *a){
	*a = *a + 1;
	return *a;
}

int main(){
	int n,result;
	scanf("%d", &n);
	result = somaMaisUm(n);
	printf("resultado: %d", result);
	printf("\nvalor de n: %d", n);
	printf("\n------------------");
	
	result = somaMaisUmPonteiro(&n);
	printf("\nresultado: %d", result);
	printf("\nvalor de n: %d", n);
	printf("------------------");	
	return 0;
}
