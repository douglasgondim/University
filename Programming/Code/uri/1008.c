#include <stdio.h>
int main(){
	int number, hours;
	float amount;
	scanf("%d %d %f", &number, &hours, &amount);
	
	printf("NUMBER = %d\n", number);
	printf("SALARY = U$ %.2f\n", hours*amount);

	return 0;
}