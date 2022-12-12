#include <stdio.h>
int main(){
	int N,i,X, in;
	X=0;
	in=0;
	scanf("%d", &N);
	for(i=0;i<N;i++){
		scanf("%d", &X);
		if(X>=10 && X<=20)
			in++;
	}
	printf("%d in\n", in);
	printf("%d out\n", N-in);




	return 0;
}