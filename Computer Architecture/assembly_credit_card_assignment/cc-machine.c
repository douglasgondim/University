#include <stdio.h>

int main(){
	int paymentForm, flagCode, cardNumber, password;
	float amount;

	printf("Enter 1 for Debit or 2 for Credit:");
	scanf("%d", &paymentForm);	

	printf("Flag code: ");
	scanf("%d", &flagCode);

	printf("Amount: $ ");
	scanf("%f", &amount);

	printf("Card number:");
	scanf("%d", &cardNumber);

	printf("Password: ");
	scanf("%d", &password);

	if (paymentForm==1){
		printf("Chosen Payment Form: Debit\n");
	}else{
		printf("Chosen Payment Form: Credit\n");
	}

	printf("Total Amount: $ %.2f\n", amount);
	printf("Credit Card Number: %d", cardNumber);





	return 0;
}