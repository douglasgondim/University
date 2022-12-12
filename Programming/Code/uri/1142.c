#include <stdio.h>
int main(){
	int N, num,i,j;
	num=1;
	scanf("%d", &N);
	for(i=0;i<N;i++){
		for(j=0;j<3;j++){
			printf("%d ", num);
			num++;
		}
		num++;
		printf("PUM\n");
	}

	return 0;
}