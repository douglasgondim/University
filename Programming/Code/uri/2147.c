#include <stdio.h>
#include <string.h>
int main(){
	int N, i;
	char word[10100];
	scanf("%d", &N);
	for(i=0;i<N;i++){
		scanf("%s", word);
		printf("%.2lf", strlen(word)/100.0);
	}

	return 0;
}