#include <stdio.h>
#define N 3
int main(){
    float matrix[N][N], out;
    char T;

    scanf(" %c", &T);

    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            scanf("%f", &matrix[i][j]);
        }
    }

    if (T == 'S'){
        for (int i=0; i<N; i++){
            for (int j=0; j<N; j++){
            	if (i+j>N-1){
            		out += matrix[i][j];
            	}
            }
        }
    }

    if (T == 'M'){
        for (int i=0; i<N; i++){
            for (int j=0; j<N; j++){
            	if (i+j>N-1){
            		out += matrix[i][j]/66;
            	}
            }
        }
    }
    printf("%.1f\n", out);


    return 0;
}
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
2 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
/*



*/