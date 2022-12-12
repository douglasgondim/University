#include <stdio.h>
int main(){
	int i, count;
	float nums[6], aux;
	count=0;
	aux=0;
	for(i=0; i<6; i++){
		scanf("%f", &nums[i]);
		if(nums[i]>=0){
			count++;
			aux+=nums[i];
		}
	}
	printf("%d valores positivos\n", count);
	printf("%.1f\n", aux/count);


	return 0;
}