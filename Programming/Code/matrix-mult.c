#include <stdio.h>
int main(){
    int matrix_1[3][3] = {{1,1,1}, {1,1,1}, {1,1,1}};
    int matrix_2[3][3] = {{1,1,1}, {1,1,1}, {1,1,1}};
    int matrix_3[3][3];

    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            matrix_3[i][j] = 0;
            for (int k=0; k<3; k++){
                matrix_3[i][j] += matrix_1[i][k] * matrix_2[k][j];
            }
        }
    }

    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            printf("%5d", matrix_3[i][j]);
        }printf("\n");
    }
    return 0;
}