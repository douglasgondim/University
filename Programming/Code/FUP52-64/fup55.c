
#include <stdio.h>
#include <stdlib.h>

//sequencia de fibonacci 
//1 1 2 3 5 8 13 21 34 ...

long int fibo(int n){
	long int f1=1,f2=1,aux;
	for(int i=1;i<n;i++){
			aux=f1+f2;
			f1=f2;
			f2=aux;
	}	
	return f1;
}

long int fiboR(int n){
	return (n==1 || n==2) ? 1 : fiboR(n-1) + fiboR(n-2);
}

int main(){
	printf("\nIterativo: %ld",fibo(45));
	printf("\nRecursivo: %ld",fiboR(45));
	
	return 0;
}
