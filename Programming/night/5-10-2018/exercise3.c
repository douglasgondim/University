// prints even numbers between 0 and 100

#include <stdio.h>
int main(){
	for (int i=0; i<=100; i++){
		if (i%2 == 0){
			printf("%d ", i);
		}
	}


	return 0;
}