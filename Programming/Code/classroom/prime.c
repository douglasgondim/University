// checks if number is prime

#include <stdio.h>

int isPrime(int num){
	int counter=0;
	for(int i=1; i<=num; i++){
		if(num%i==0){
			counter++;
		}
	}
	if(counter==2){
		return 1;
	}
	return 0;
}


int main(){
	int n, out;
	printf("Enter any positive number: ");
	scanf("%d", &n);
	out = isPrime(n);

	if(out==1){
		printf("Is prime.\n");
	}else{
		printf("Is not prime.\n");
	}



	return 0;
}