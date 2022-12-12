#include <stdio.h>
int main(){
	int N, X, Y, i,j,sum;
	scanf("%d", &N);
	for(i=0;i<N;i++){
		sum=0;
		scanf("%d %d", &X, &Y);
		for(j=0;j<X;j++){

			if(Y%2==0){
				Y+1;
			}
			sum+=Y;
			
			Y+=2;
		
		}
	printf("%d\n", sum);	
	}
	


	return 0;
}