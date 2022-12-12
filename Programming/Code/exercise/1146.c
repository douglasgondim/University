#include <stdio.h>
int main(){
	int x, i;
	
	while (x != 0){
		printf("\n");
		scanf("%d", &x);

		for(i=1; i <= x-1; i++){
			printf("%d ", i);
		}
		printf("%d", x);
	}	


	return 0;
}