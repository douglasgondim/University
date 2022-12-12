#include <stdio.h>
int main(){
	int N,num,i;
	num=1;
	scanf("%d", &N);
	for(i=0;i<N;i++){
		printf("%d %d %d\n", num, num*num, num*num*num);
		num++;
	}


	return 0;
}