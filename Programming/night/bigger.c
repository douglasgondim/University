#include <stdio.h>
int main(){
	float a, b, bigger;
	scanf("%f %f", &a, &b);
	if (a > b){
		printf("%.2f", a);
	}else{
		printf("%.2f", b);
	}

	return 0;
}