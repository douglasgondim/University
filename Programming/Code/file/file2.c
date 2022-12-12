#include <stdio.h>
int main(){
	FILE *fp;
	char line[100];
	fp = fopen("douglas", "r");
	if(fp == NULL){
		printf("ERROR\n");
		return 0;
	}

	while(!feof(fp)){
		fgets(line, 100, fp);
		printf("%s", line);
	}

	fclose(fp);

	return 0;
}