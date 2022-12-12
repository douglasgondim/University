#include <stdio.h>
int main(){
	int X, Y,i,sum;
	scanf("%d %d", &X, &Y);
	sum=0;
	if(X<Y){
		for(i=X;i<=Y;i++){
			if(i%13!=0)
				sum+=i;
		}
	}else{
		for(i=Y;i<=X;i++){
			if(i%13!=0)
				sum+=i;
		}
	}
	printf("%d\n", sum);

	return 0;
}