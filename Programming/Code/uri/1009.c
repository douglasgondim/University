#include <stdio.h>
int main(){
	char name[50];
	float wage, sold;
	scanf("%s", name);
	scanf("%f %f", &wage, &sold);
	printf("TOTAL = R$ %.2f\n", wage +(sold*0.15));

	return 0;
}