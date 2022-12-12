#include <stdio.h>
int main(){
	int n[10], num, i;
	scanf("%d", &num);
	n[0] = num;
	printf("N[0] = %d\n", n[0] );
	for (i=1; i<10; i++){
		n[i] = n[i-1] * 2;
		printf("N[%d] = %d\n", i, n[i]);
	}




	return 0;
}