#include <stdio.h>
int main(){
	int n;
	scanf("%d", &n);
	if (n % 10 == 0){
		printf("It's divisible by 10\n");
	}if(n % 5 == 0){
		printf("It's divisible by 5\n");
	}if (n % 2 == 0){
		printf("It's divisible by 2\n");
	}if ((n % 10 != 0) && (n % 5 != 0) && (n % 2 != 0)){
		printf("It's not divisible by either 10, 5 or 2\n");
	}

	return 0;
}