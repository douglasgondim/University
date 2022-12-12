// calculates the fatorial of a number

#include <stdio.h>
int main(){
	int n, factorial;
	scanf("%d", &n);

	factorial = 1;
	for (int i=n; i>=1; i--){
		factorial *= i;
	}
	printf("%d\n", factorial);


	return 0;
}