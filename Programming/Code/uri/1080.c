#include <stdio.h>
int main(){
	int num, i, bigger, position;
	scanf("%d", &num);
	bigger = num;
	position = 1;
	for(i=2;i<101;i++){
		scanf("%d", &num);
		if(num>bigger){
			bigger = num;
			position = i;
		}
	}
	printf("%d\n", bigger);
	printf("%d\n", position);
	return 0;
}