#include <stdio.h>
#include <stdlib.h>
int isPerfect(int num){
	int i, sum=0;
	for(i=1;i<num;i++){
		if(num%i==0)
			sum+=i;
	}
	if(num==sum)
		return 1;
	else
		return 0;
}
int main(){
	int *p, N, i;
	scanf("%d", &N);
	p = (int*) malloc(N*sizeof(int));
	for(i=0;i<N;i++){
		scanf("%d", &p[i]);
		if(isPerfect(p[i])==1)
			printf("%d eh perfeito\n", p[i]);
		else
			printf("%d nao eh perfeito\n", p[i]);
	}


	return 0;
}