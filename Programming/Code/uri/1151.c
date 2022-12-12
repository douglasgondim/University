#include <stdio.h>
int main(){
	int N, fib, nextFib,aux,i;
	fib =0;
	nextFib =1;
	scanf("%d", &N);
	printf("%d", fib);
	for(i=1;i<N;i++){	
		aux = fib;
		fib=nextFib;
		nextFib += aux;
		printf(" %d", fib);
	}
	printf("\n");


	return 0;
}