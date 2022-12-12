#include <stdio.h>
#include <math.h>
int main(){
	float num1, num2;
	char operator;

	scanf("%f %f", &num1, &num2);
	scanf(" %c", &operator);

	switch(operator){
		case '+':
			printf("The result is: %.2f \n", num1 + num2);
			break;
		case '-':
			printf("The result is: %.2f \n", num1-num2);
			break;
		case '*':
			printf("The result is: %.2f \n", num1*num2);
			break;
		case '/':
			printf("The result is: %.2f \n", num1/num2);
			break;
		
		default:
			printf("Invalid Operator\n");
			break;
	}




	return 0;
}