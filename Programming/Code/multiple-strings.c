#include <stdio.h>
int main(){
	char name[100];
	printf("\nEnter your full name: \n");
	scanf("%[^\n]s", name);
	printf("%s\n", name);

	return 0;
}