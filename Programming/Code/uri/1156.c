#include <stdio.h>
int main(){
	float s,num, num_2;
	num=1;
	num_2=1;
	s=0;
	while(num<=39){
		s += (num/num_2);
		num+=2;
		num_2 *=2;
	}
	printf("%.2f\n", s);


	return 0;
}