#include <stdio.h>
#define QTT 5
int main(){
	int vector[QTT], vector1[QTT];

	for (int i=0; i<QTT; i++){
	scanf("%d", &vector[i]);
	
		if (i % 2 == 0){
			vector1[i] = (vector[i] * 2);
		}else{
			vector1[i] = (vector[i] * 3);
		}
		printf("%d ", vector1[i]);
	}

	return 0;
}