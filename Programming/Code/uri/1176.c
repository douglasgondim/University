#include <stdio.h>
int main(){	
	int i, j, num, T;
	long long int fib, nextFib, aux;
	scanf("%d", &T);
	for(j=0;j<T;j++){
		scanf("%d", &num);
		fib=0;
		nextFib=1;
		for(i=0;i<num;i++){
			aux=fib;
			fib=nextFib;
			nextFib=fib+aux;
		}
		printf("Fib(%d) = %lli\n", num, fib);

	}

	return 0;
}