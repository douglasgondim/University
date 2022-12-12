#include <stdio.h>
int main(){
	int vector[10], biggest, smallest;
	for(int i=0; i<10; i++){
		scanf("%d", &vector[i]);
	}

	biggest = vector[0];
	smallest = vector[0];
	for(int i=1; i<10; i++){
		if(vector[i]<smallest){
			smallest = vector[i];
		}else if(vector[i]>biggest){
			biggest = vector[i];
		}
	}

	printf("\nThe biggest number is: %d", biggest);
	printf("\nThe smallest number is: %d", smallest);

	return 0;
}

semi-collon