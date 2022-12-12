#include <stdio.h>
int main(){
	int N,i, num;
	scanf("%d", &N);
	for(i=0;i<N;i++){
		scanf("%d", &num);
		if(num!=0){
			if(num%2!=0)
				printf("ODD");
			else
				printf("EVEN");
			if(num>0)
				printf(" POSITIVE\n");
			else
				printf(" NEGATIVE\n");
		}else
			printf("NULL\n");
	}
	return 0;
}