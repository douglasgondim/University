#include <stdio.h>
int main(){
	float a, b, c;
	scanf("%f %f %f", &a, &b, &c);
	if ((a + b > c) && (b + c > a) && (a + c > b)){
		if ((a==b) && (b==c)){
			printf("Equilateral");
		}else if ((a==b) && (b!=c) || (a==c) && (a!=b)){
			printf("Isosceles");
		}else{
			printf("Scalene");
		}
	}else{
		printf("Not a triangle");
	}

	return 0;
}