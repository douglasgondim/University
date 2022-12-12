/*
	Pointers: points to a memory adress
	int *p
   */


#include <stdio.h>
int main(){
	int num = 5;
	int *p;
	p = &num; // num memory position of num to p

	// prints the content of referenced memory
	printf("%d\n", *p);
	*p = 1000;

	printf("%d\n", num);


	num = 100;
	printf("%d\n", *p);



	return 0;
}