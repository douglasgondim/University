#include <stdio.h>
int main(){
	int X, Y, i;
	scanf("%d %d", &X, &Y);
	while(X!=Y){
		if(X<Y)
			printf("Crescente\n");
		else
			printf("Decrescente\n");
		scanf("%d %d", &X, &Y);
	}

	return 0;
}