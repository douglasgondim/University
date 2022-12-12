#include <stdio.h>
#define N 12
int main(){
	int L;
	float matrix[N][N], out;
	char T;

	scanf("%d", &L);
	scanf(" %c", &T);

	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			scanf("%f", &matrix[i][j]);
		}
	}

	if (T == 'S'){
		for (int j=0; j<N; j++){
			out += matrix[j][L];
		}

	}else if (T == 'M'){
		for (int j=0; j<N; j++){
			out += matrix[j][L]/12;
		}


	}
	printf("%.1f\n", out);


	return 0;
}