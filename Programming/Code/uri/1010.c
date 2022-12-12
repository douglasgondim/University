#include <stdio.h>
int main(){
	int code1, code2, units1, units2;
	float price1, price2;
	float total;
	scanf("%d %d %f %d %d %f", &code1, &units1, &price1, &code2, &units2, &price2);
	total = units1*price1 + units2*price2;
	printf("VALOR A PAGAR: R$ %.2f\n", total);



	return 0;
}