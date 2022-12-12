

#include <stdio.h>

//calcule e retorne o mdc de a e b
int mdc_1(int a, int b){
	int div=1;
	for(int i=1; i <= a; i++){
		if (a%i==0 && b%i==0)
			div = i;
	}
	return div;
}

int mdc_2 (int a, int b){
	return (a%b==0) ? b : mdc_2(b,a%b);
}

int main(){
	int num1, num2;
	scanf("%d %d", &num1, &num2);
	printf("O mdc de %d e %d é: %d",num1, num2, mdc_2(num1,num2));

	return 0;
}
