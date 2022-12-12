#include <stdio.h>
int main(){
	int i,j;
	i=1;
	for(j=60;j>=0;j=j-5){
		printf("I=%d", i);
		printf(" J=%d\n", j);
		i=i+3;
	}

	return 0;
}