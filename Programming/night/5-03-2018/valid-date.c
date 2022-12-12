#include <stdio.h>
int main(){
	int d, m, y;
	scanf("%d %d %d", &d, &m, &y);
	if (((d >= 1) && (d <= 31))  &&  ((m >=1) && (m<=12)) && (2018-y <=200)){
		printf("Valid date");
	}else{
		printf("Invalid Date");
	}

	return 0;
	
}