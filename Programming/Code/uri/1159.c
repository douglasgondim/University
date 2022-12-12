#include <stdio.h>
int main(){
	int X,sum,i;
	scanf("%d", &X);
	while(X!=0){
		sum=0;
		if(X%2!=0)
			X++;
		for(i=0;i<5;i++){
			sum+=X;
			X+=2;
		}

		printf("%d\n", sum);
		scanf("%d", &X);
	}

	return 0;
}