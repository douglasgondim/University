#include <stdio.h>
int main(){
	int vector[10];

	for(int i=0; i<10; i++){
		scanf("%d", &vector[i]);
	}
	for(int i=0; i<10; i++){
		if(vector[i]<0){
			vector[i] = 0;
		}
	}
	for(int i=0; i<10; i++){
		printf("%d ", vector[i]);
	}


	return 0;
}