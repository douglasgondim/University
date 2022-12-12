#include <stdio.h>

char isPrime(int n){
	int i, divides;
	divides=0;
	for(i=2;i<=n;i++)
		if(n%i==0)
			divides++;
	return divides;
}

int main(){
	int N, X,i;
	scanf("%d", &N);
	for(i=0;i<N;i++){
		scanf("%d", &X);
		if(isPrime(X)==1)
			printf("%d eh primo\n", X);
		else
			printf("%d nao eh primo\n", X);
	}



	return 0;
}