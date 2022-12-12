#include <stdio.h>
int main(){
	int N, i, g;
	float grade[3];
	scanf("%d", &N);
	for(g=0;g<N;g++){
		for(i=0;i<3;i++)
			scanf("%f", &grade[i]);
		printf("%.1f\n", (grade[0]*2+grade[1]*3+grade[2]*5)/10);
	}

	return 0;
}