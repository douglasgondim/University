#include <stdio.h>
int factorialN(int N){
	if(N>1)
		return N*factorialN(N-1);
	else
		return 1;
}
int main(){
	int N;
	scanf("%d", &N);
	printf("%d\n", factorialN(N));

	return 0;
}