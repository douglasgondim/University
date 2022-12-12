/*9. Leia o salário de um trabalhador e 
o valor da prestação de um empréstimo. 
Se a prestação for maior que 20% do salário, imprima: 
Empréstimo não concedido, 
caso contrário imprima: Empréstimo concedido.*/

#include <stdio.h>
int main(){
	float wage, installment;
	printf("Enter Wage: ");
	scanf("%f", &wage);
	printf("Enter Installment Value: ");
	scanf("%f", &installment);
	if (installment > (wage * 0.20)){
		printf("Loan Denied!");
	}else{
		printf("Loan Approved!");
	}

	return 0;
}