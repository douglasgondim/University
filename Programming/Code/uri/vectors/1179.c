#include <stdio.h>
int main(){
	int n;
	scanf("%d", &n);
	int x[n];

	for (int i=0; i<n; i++){
		scanf("%d", &x[i]);
	} 

	for (int i=0; i<n; i++){
		printf("%d ", x[i]);
	} 

	return 0;
}