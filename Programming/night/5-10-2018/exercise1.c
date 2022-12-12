/* Make a program that read 5 floats and prints 
the squares of each. At the end, print the sum of them */

#include <stdio.h>
int main(){
	float n1, n2, n3, n4, n5, sum;
	scanf("%f %f %f %f %f", &n1, &n2, &n3, &n4, &n5);
	printf("%.2f \n", n1*n1);
	printf("%.2f \n", n2*n2);
	printf("%.2f \n", n3*n3);
	printf("%.2f \n", n4*n4);
	printf("%.2f \n", n5*n5);

	printf("%.2f", n1*n1+n2*n2+n3*n3+n4*n4+n5*n5 );


	return 0;
}