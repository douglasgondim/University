/* Make a program that calculates the average of 5 integers
and print the result */

#include <stdio.h>
int main(){
	int n1, n2, n3, n4, n5; 
	float average;
	scanf("%d %d %d %d %d", &n1, &n2, &n3, &n4, &n5);
	average = (n1+n2+n3+n4+n5)/5;
	printf("%.2f", average);


	return 0;
}