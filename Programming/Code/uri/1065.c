#include <stdio.h>
int main(){
	int num[5], i, count;
	count = 0;
	for(i=0;i<5;i++){
		scanf("%d", &num[i]);
		if(num[i]%2==0)
			count++;
	}

	printf("%d valores pares\n", count);


	return 0;
}