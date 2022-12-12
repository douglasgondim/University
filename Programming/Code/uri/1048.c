#include <stdio.h>
int main(){
	float salary, readjustment;
	scanf("%f", &salary);
	if(salary>=0 && salary<=400)
		readjustment = 0.15;
	else if(salary>400 && salary<=800)
		readjustment = 0.12;
	else if(salary>800 && salary<=1200)
		readjustment = 0.10;
	else if(salary>1200 && salary<=2000)
		readjustment = 0.07;
	else if(salary>2000)
		readjustment = 0.04;
	printf("Novo salario: %.2f\n", salary+salary*readjustment);
	printf("Reajuste ganho: %.2f\n", salary*readjustment);
	printf("Em percentual: %.0f %%\n", readjustment*100 );


	return 0;
}