#include <stdio.h>
int main(){
	int bigger;

	for(int i=1;i<9999;i++){
		if(i%13==0){
			bigger = i;
		}
	}
	printf("%d\n", bigger);

	return 0;
}