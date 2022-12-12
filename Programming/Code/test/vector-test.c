#include <stdio.h>
int main(){
	int v[3];
	v[0] = 1;
	v[1] = 2;
	v[2] = 3;

	printf("%d", &v[0]);

	return 0;
}