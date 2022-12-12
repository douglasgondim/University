#include <stdio.h>
int main(){
	float salary;
	scanf("%f", &salary);
	if(salary<=2000)
		printf("Isento\n");
	else if(salary>2000 && salary<=3000)
		printf("R$ %.2f\n", (salary-2000)*0.08);
	else if(salary>3000 && salary<=4500)
		printf("R$ %.2f\n", 80+(salary-3000)*0.18);
	else
		printf("R$ %.2f\n", 350+(salary-4500)*0.28); 
	return 0;
}