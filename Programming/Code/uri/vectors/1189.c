#include <stdio.h>
#define N 12
int main(){
    int f, acm;
    float matrix[N][N], out;
    char T;

    scanf(" %c", &T);

    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            scanf("%f", &matrix[i][j]);
        }
    }
    f =0;
    acm=0;
    if (T == 'S'){
        for (int i=1; i<N-1; i++){
            for (int j=0; j<5; j++){
                if (i>j){
                    out += matrix[i][j];           	
                }
            }

            f++;
        }
    }else if (T == 'M'){
        for (int i=1; i<N-1; i++){
            for (int j=0; j<5; j++){
                out += matrix[i][j];
                acm++;               
            }
            f++;
        }
    out = out/acm;
    }

    printf("%.1f\n", out);


    return 0;   
}
    