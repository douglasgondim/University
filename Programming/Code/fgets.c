#include <stdio.h>
int main(){
	char name[100];
	printf("Enter your full name: \n");

	fgets(name, 100, stdin);
	printf("%s\n", name);



	return 0;
}