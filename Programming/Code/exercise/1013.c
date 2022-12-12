#include <stdio.h>
#include <stdlib.h>

int main(){
	int a, b, c, BiggerAB;
	scanf("%d %d %d", &a, &b, &c);
	BiggerAB = (a+b + abs(a-b)) / 2;
	a = BiggerAB;
	BiggerAB = (a+c + abs(a-c)) / 2;
	printf("%d eh o maior\n", BiggerAB);

	return 0;
}