#include <stdio.h>
int main(){
	int t, N[1000], f;
	scanf("%d", &t);

	if (t>=2 && t<=50){
		f=0;
		while (f <1000){
			for (int i=0; i<t; i++){
				N[f] = i;
				f++;
			}
		}
	}

	for (int i=0; i<1000; i++){
		printf("N[%d] = %d\n", i, N[i]);
	}


	return 0;
}