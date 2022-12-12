#include <stdio.h>

struct A {
	int a,b,c; //4
};

union B {
	int a,b,c;
	char e;
	float d;
};

int main(){
	printf("\n%lu", sizeof(int));
	printf("\n%lu", sizeof(struct A));
	printf("\n%lu", sizeof(union B));
	return 0;
}
