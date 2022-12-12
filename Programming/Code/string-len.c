#include <stdio.h>
#include <string.h>
int main(){
    char name[100];
    int count=0;

    scanf("%s", name);

    while (name[count] != '\0'){
    	count++;
    }

    printf("Length: %d\n", count);

    printf("Using function: %d\n", strlen(name));
	return 0;
}