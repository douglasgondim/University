#include <stdio.h>
int main(){
	float S,i;
	S=0;
	for(i=1;i<101;i++)
		S += 1/i;
	printf("%.2f\n", S);

	return 0;
}