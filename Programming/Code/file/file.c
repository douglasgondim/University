#include <stdio.h>
int main(){
	FILE *fp;

	fp = fopen("douglas", "w+");

	fputs("Douglas Gondim \n", fp);
	fputs("Is cute!\n", fp);
	fputs("Too much!!\n", fp);

	fclose(fp);

	return 0;
}