
#include <stdio.h>

int main(){
	char nome_1[100], nome_2[100]
		,nome_3[100];
	//espaço para ignorar o \n final
	scanf(" %[^\n]s", nome_1);
	scanf(" %[^\n]s", nome_2);
	scanf(" %[^\n]s", nome_3);
	
	printf("%s\n", nome_1);
	printf("%s\n", nome_2);
	printf("%s\n", nome_3);

	return 0;
}
