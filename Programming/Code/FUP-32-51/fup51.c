#include <stdio.h>

void inv(int n) {
	int aux;
	while(n!=0){
		aux = n%10;
		n = (n)/10;
		printf("%d", aux);
	}
}

void invRec(int n) {
	if(n>9){
			printf("%d",n%10);
			return invRec(n/10);
	}
	else{
			printf("%d",n);
	}

}

int main() {
	
	invRec(0);
	
	return 0;
}
