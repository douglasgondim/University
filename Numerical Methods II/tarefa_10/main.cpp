#include <iostream>
#include <math.h>

using namespace std;
#include "Matrix.hpp"

template<typename T>
void regularPower(Matrix<T> A, Matrix<T> v, double EPSILON){
    double lambdaOld;
    double lambdaNew = 0;

    Matrix<T> vNew = v.copy();
    Matrix<T> vOld;
    Matrix<T> xOld;
    cout << vNew.transpose() * vNew << endl;     

    while(abs((lambdaNew - lambdaOld) / lambdaNew) > EPSILON){
        lambdaOld = lambdaNew;
        vOld = vNew;
        xOld = vOld/ (vOld.transpose() * vOld).sqrtmat();
        vNew = A * xOld;
        lambdaNew = xOld.transpose() * vNew;

    }

    cout << "Autovalor = " << lambdaNew << ", Autovetor = " << xOld;


    
}
int main(){
    Matrix<double> A;
    int m, n; // num de linhas e colunas
    Matrix<double> v;
    double EPSILON;

    cout << "Bem vindo ao programa que calcula o método da potência regular\n" << endl;

    cout << "Digite o número de linhas da matriz A: ";
    cin >> m;
    
    cout << "Digite o número de colunas da matriz A: ";
    cin >> n;

    cout << "Digite a sua matriz A (da esquerda para direita e de cima para baixo com valores separados por espaço):" << endl;

    A = Matrix<double>(m, n);
    cin >> A;

    cout << "Digite os valores arbritários do vetor inicial (separados por espaço):" << endl;

    v = Matrix<double>(1, m);
    cin >> v;

    cout << "Digite a tolerância desejada: ";
    cin >> EPSILON;

    regularPower<double>(A, v, EPSILON);



    
    return 0;
}