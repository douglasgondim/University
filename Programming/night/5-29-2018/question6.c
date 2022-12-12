#include <stdio.h>
int main(){
	int num, count, sum;
	count=0;
	sum=0;
	num=1;
	while(num != 0){
		scanf("%d", &num);
		if(num<0){
			count++;
		}else{
			sum += num;
		}
	}

	printf("\nThe number of negative numbers is: %d", count);
	printf("\nThe sum of positives is: %d", sum);

	return 0;
}