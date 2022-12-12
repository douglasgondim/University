#include <stdio.h>
int contaDigitos(int n, int d){
	int cont=0;
	while(n!=0){
		if(d==(n%10))
			cont++;
	n = n/10;
	}
	return cont;
}
int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	for(int i=1; i<10; i++){
		if(contaDigitos(a,i) != contaDigitos(b,i)){
			printf("A nao eh permutacao de B.\n");
			return 0;
		}
	}
	printf("A eh permutacao de B.\n");
	return 0;
}