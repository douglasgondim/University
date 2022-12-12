#include <stdio.h>
#define N 12
int main(){
	int f;
	float matrix[N][N], out;
	char T;

	scanf(" %c", &T);

	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			scanf("%f", &matrix[i][j]);
		}
	}
	f=1;
	if (T == 'S'){
		for (int i=0; i<5; i++){
			for (int j=0+f; j<N-f; j++){
				out += matrix[i][j];
				
			}
			f++;
		}
	}

	if (T == 'M'){
		for (int i=0; i<N; i++){
			for (int j=0; j<N-i-1; j++){
				out += matrix[i][j]/66;
				
			}
		}
	}
	printf("%.1f\n", out);


	return 0;
}