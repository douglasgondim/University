#include <stdio.h>
int main(){
	char name_1[100], name_2[100], name_3[100];
	scanf(" %[^\n]s", name_1);
	scanf(" %[^\n]s", name_2);
	scanf(" %[^\n]s", name_3);

	printf("%s\n", name_1);
	printf("%s\n", name_2);
	printf("%s\n", name_3);

	return 0;
}