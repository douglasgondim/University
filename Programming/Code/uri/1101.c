#include <stdio.h>
int main(){
	int M, N, i, sum;
	scanf("%d %d", &M, &N);
	while(M>0 && N>0){
		sum=0;
		if(M<N){
			for(i=M;i<=N;i++){
				printf("%d ", i);
				sum+=i;
			}
		}else{
			for(i=N;i<=M;i++){
				printf("%d ", i);
				sum+=i;
			}
		}
		printf("Sum=%d\n", sum);
		scanf("%d %d", &M, &N);
	}
	
	return 0;
}