#include <stdio.h>
int main(){
	int n, num[n], i;
	scanf("%d", &n);
	for (i=0; i<n; i++){
		scanf("%d", &num[i])
	}
	for (i=n; i>=0; i--){
		printf("%d", num[i]);
	}

	return 0;
}