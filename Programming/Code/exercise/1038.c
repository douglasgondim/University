#include <stdio.h>
int main(){
	int X, Y;
	float price;
	scanf("%d %d", &X, &Y);
	switch (X){
		case 1: 
			price = 4;
			break;
		
		case 2: 
			price = 4.50;
			break;
		
		case 3: 
			price = 5;
			break;
		
		case 4: 
			price = 2;
			break;
		
		case 5: 
			price = 1.5;
			break;
	}
	printf("Total: R$ %.2f\n", price * Y);

	return 0;
}