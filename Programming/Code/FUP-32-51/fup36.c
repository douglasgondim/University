


#include <stdio.h>

int main(){
	int num = 10;
	int *p;
	int **q;
	
	p = &num;
	q = &p;
	
	printf("%d", **q);
	return 0;
}
