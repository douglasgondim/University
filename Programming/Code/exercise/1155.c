#include <stdio.h>
int main(){
	float i, s;
	s=0;
	for (i=1; i <= 100; i++){
		s += 1/i; 
	}
	printf("%.2f\n", s);

	return 0;
}