#include <stdio.h>
int main(){
	int vector[10], count;
	
	for(int i=0; i<10; i++){
		scanf("%d", &vector[i]);
	}
	count=0;
	for(int i=0; i<10; i++){
		if(vector[i]%2==0){
			count++;
			printf("%d ", vector[i]);
		}
	}
	printf("\n%d even numbers", count);



	return 0;
}