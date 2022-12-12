#include <stdio.h>
int main(){

	char name[100], cpf[15];
	scanf("%s", name);
	scanf("%s", cpf);

	printf("\n%s\n", name);
	printf("%s\n", cpf);

	int i=0;
	while (name[i] != '\0'){
		printf("%c ", name[i]);
		i++;
	}

	return 0;
}