#include <stdio.h>

int sumOfN(int X, int Y){
	int sum, i;
	sum=0;
	if(X<Y)
		if(X%2==0)
			for(i=X+1;i<Y;i=i+2)
				sum+=i;
		else
			for(i=X+2;i<Y;i=i+2)
				sum+=i;
	else
		if(X%2==0)
			for(i=X-1;i>Y;i=i-2)
				sum+=i;
		else
			for(i=X-2;i>Y;i=i-2)
				sum+=i;
	return sum;
}
int main(){
	int X, Y, N,i;
	scanf("%d", &N);
	for(i=0;i<N;i++){
		scanf("%d %d", &X, &Y);
		printf("%d\n", sumOfN(X,Y));
	}

}