#include <stdio.h>
int main(){
	int alcohol, gas, diesel, code;
	alcohol=0;
	gas=0;
	diesel=0;
	scanf("%d", &code);
	while(code!=4){
		switch(code){
			case 1: 
				alcohol++;
				break;
			case 2:
				gas++;
				break;
			case 3:
				diesel++;
				break;
			default:
				break;
				
		}
		scanf("%d", &code);
	}
	printf("MUITO OBRIGADO\n");
	printf("Alcool: %d\n", alcohol);
	printf("Gasolina: %d\n", gas);
	printf("Diesel: %d\n", diesel);


	return 0;
}