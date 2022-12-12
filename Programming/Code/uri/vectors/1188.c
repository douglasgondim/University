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
    f =0;
    if (T == 'S'){
        for (int i=N-5; i<N; i++){
            for (int j=N-7-f; j<N-5+f; j++){
                out += matrix[i][j];            	
            }
            f++;
        }
    }else if (T == 'M'){
        for (int i=N-5; i<N; i++){
            for (int j=N-7-f; j<N-5+f; j++){
                out += matrix[i][j]/30;                
            }
            f++;
        }
    }
    printf("%.1f\n", out);


    return 0;
}
