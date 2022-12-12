#include <stdio.h>
int main(){
	int n, triangular, i;
	scanf("%d", &n);
	triangular = 0;
	for(i=1; i<n; i++){
		triangular = (i) * (i+1) * (i+2);
		printf("%d ", triangular);
	}


	return 0;
}