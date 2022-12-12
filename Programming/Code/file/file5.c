#include <stdio.h>
#include <string.h>
int main(){
	FILE *fp;

	char line[100];
	char name[30];
	char lastName[30];
	char fullName[60];
	int age;
	float weight, height;

	fp = fopen("data-file", "r");
	if(fp == NULL){
		printf("ERROR OPENING FILE!\n");
	}

	while(!feof(fp)){
		fgets(line, 100, fp);
		sscanf(line, "%s %s %d %f %f", name, lastName, &age, &weight, &height);
		strcpy(fullName, "");
		strcat(fullName, name);
		strcat(fullName, " ");
		strcat(fullName, lastName);

		printf("Name: %s\n", name);
		printf("Last Name: %s\n", lastName);
		printf("Full name: %s\n", fullName);
		printf("Age: %d\n", age);
		printf("Weight: %.2f Kg\n", weight);
		printf("Height: %.2f m\n", height);
	}




	fclose(fp);



	return 0;
}