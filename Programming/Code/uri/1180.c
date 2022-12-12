#include <stdio.h>
#include <stdlib.h>
int main(){
	int *P, N, i, position, smaller;
	scanf("%d", &N);
	P =(int*) malloc(N*sizeof(int));
	scanf("%d", &P[0]);
	position=0;
	smaller = P[0];
	for(i=1;i<N;i++){
		scanf("%d", &P[i]);
		if(P[i]<smaller){
			position=i;
			smaller=P[i];
		}
	}
	printf("Menor valor: %d\n", smaller);
	printf("Posicao: %d\n", position);



	return 0;
}