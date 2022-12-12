
#include <stdio.h>

int main(){
	int num_1 = 10;
	int num_2 = 20;
	
	int *p;
	
	p = &num_1; //aponta para a memoria de num_1;
	
	*p = *p * 10;
	
	p = &num_2;
	
	*p = *p * 10;
	
	printf("%d \n %d\n", num_1, num_2);
	
	
	return 0;
}
