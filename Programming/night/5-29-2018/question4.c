#include <stdio.h>
int main(){
	int vector[10], biggest, position;
	for(int i=0; i<10; i++){
		scanf("%d", &vector[i]);
	}

	biggest = vector[0];
	for(int i=1; i<10; i++){
		if(vector[i]>biggest){
			biggest = vector[i];
			position = i;
		}
	}
	printf("\nThe biggest value is: %d in the position %d", biggest, position);



	return 0;
}