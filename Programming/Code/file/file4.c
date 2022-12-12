#include <stdio.h>
int main(){
	FILE *fp;

	fp = fopen("douglas", "a");
	if(fp == NULL){
		printf("ERROR\n");
		return 0;
	}

	fputs("appended\n", fp);

	fclose(fp);


	return 0;
}