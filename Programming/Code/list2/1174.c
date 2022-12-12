#include <stdio.h>
#define qtt 100
int main(){
	float a[qtt];
	int i;
	for (i=0; i<qtt; i++){
		scanf("%f", &a[i]);
		if (a[i] <= 10){
			printf("A[%d] = %.1f\n", i, a[i]);
		}
	}

	return 0;
}