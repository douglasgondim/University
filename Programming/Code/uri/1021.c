#include <stdio.h>
#include <math.h>
int main(){
	int N, fraction;
	float num;
	scanf("%f", &num);
	N = num;
	fraction = roundf((num-N)*100);


	printf("NOTAS:\n");
	printf("%d nota(s) de R$ 100.00\n", N/100);
	N = N%100;
	printf("%d nota(s) de R$ 50.00\n", N/50);
	N = N%50;
	printf("%d nota(s) de R$ 20.00\n", N/20);
	N = N%20;
	printf("%d nota(s) de R$ 10.00\n", N/10);
	N = N%10;
	printf("%d nota(s) de R$ 5.00\n", N/5);
	N = N%5;
	printf("%d nota(s) de R$ 2.00\n", N/2);
	N = N%2;
	
	printf("MOEDAS:\n");
	printf("%d moeda(s) de R$ 1.00\n", N/1);
	printf("%d moeda(s) de R$ 0.50\n", fraction/50);
	fraction = fraction%50;
	printf("%d moeda(s) de R$ 0.25\n", fraction/25);
	fraction = fraction%25;
	printf("%d moeda(s) de R$ 0.10\n", fraction/10);
	fraction = fraction%10;
	printf("%d moeda(s) de R$ 0.05\n", fraction/5);
	fraction = fraction%5;
	printf("%d moeda(s) de R$ 0.01\n", fraction/1);
	
	return 0;
}