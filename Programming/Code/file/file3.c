#include <stdio.h>
int main(){
	FILE *fp;

	char c;
	fp = fopen("douglas", "r");
	if(fp == NULL){
		printf("ERROR!\n");
		return 0;
	}

	while(!feof(fp)){
		c = fgetc(fp);
		printf("%c", c);

	}

	fclose(fp);

	return 0;
}