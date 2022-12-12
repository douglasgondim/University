#include <stdio.h>
int main(){
	int N[1000], i=0, j, num;
	scanf("%d", &num);
	while(i<1000){
		for(j=0;j<num;j++){
			N[i] = j;
			i++;
		}
	}
	for(i=0;i<1000;i++)
		printf("N[%d] = %d\n", i, N[i]);

	return 0;
}