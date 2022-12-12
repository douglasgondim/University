#include <stdio.h>
int main(){
	int i, count;
	float vector[6];
	count=0;
	for(i=0; i<6; i++){
		scanf("%f", &vector[i]);
		if(vector[i]>0)
			count++;
	}
	printf("%d valores positivos\n", count);

	return 0;
}