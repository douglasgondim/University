// calculates the average of 2 numbers
#include <stdio.h>
int main(){
	float a, b, average;
	scanf("%f %f", &a, &b);
	average = (a + b) / 2;
	printf("%.2f", average);

	return 0;
}