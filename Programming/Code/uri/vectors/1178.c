#include <stdio.h>
int main(){
	double N[100], x;
	scanf("%lf", &x);
	for (int i=0; i<100; i++){
		N[i] = x;
		x = x/2;
		printf("N[%d] = %.4lf\n", i, N[i]);
	}

	return 0;
}