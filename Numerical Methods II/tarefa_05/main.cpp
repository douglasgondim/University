#include <iostream>
#include "math.h"
#include <limits>
using namespace std;

// double f(double x){
//     return pow(sin(2*x) + 4*pow(x, 2) + 3*x, 2);
// }
double f(double x){
    return 10 - 0.2 * sin(8*x) * exp(-pow(x, 2.5));
}


double x(double xi, double xf, double alpha){
    return (xi+xf)/2.0 + ((xf-xi)/2.0)*alpha;
}

double legendre(int numOfPoints, double xi, double xf){
    double *alpha = new double[numOfPoints];
    double *w = new double[numOfPoints];

    switch (numOfPoints){
        case 2:
            alpha[0] = -sqrt(1.0/3);
            alpha[1] = sqrt(1.0/3);

            w[0] = 1.0;
            w[1] = 1.0;
            break;
        case 3:
            alpha[0] = -sqrt(3.0/5);
            alpha[1] = 0;
            alpha[2] = sqrt(3.0/5);

            w[0] = 5.0/9;
            w[1] = 8.0/9;
            w[2] = w[0];
            break;
        case 4:
            alpha[0] = -sqrt(3.0/7 - (2*sqrt(6.0/5))/7.0);
            alpha[1] = -sqrt(3.0/7 + (2*sqrt(6.0/5))/7.0);
            alpha[2] =  sqrt(3.0/7 - (2*sqrt(6.0/5))/7.0);
            alpha[3] =  sqrt(3.0/7 + (2*sqrt(6.0/5))/7.0);

            w[0] = 0.652145;
            w[1] = 0.347855;
            w[2] = w[0];
            w[3] = w[1];

            break;

        default:{
            return -1;
        }
        
    }

    double res = 0;
    for(int i=0; i < numOfPoints; ++i)  res += f(x(xi, xf, alpha[i])) * w[i];
    res *= (xf-xi)/2.0;
    return res;
    
}


int main(){
    int numOfPoints;
    double xf, xi, EPSILON;
    cout << "Cáculo de integração de Legendre" << endl << endl;

    cout << "Digite o número de pontos: ";
    cin >> numOfPoints;

    // cout << "Digite o limite inferior: ";
    // cin >> xi;

    // cout << "Digite o limite superior: ";
    // cin >> xf;

    xi = 0;
    xf = M_PI;
    cout << "Digite o Erro esperado: ";
    cin >> EPSILON;


    double curr = 0;
    double prev = -INFINITY;
    int n = 1;

    while(abs(curr - prev) > EPSILON){
        n *= 2;
        double delta = (xf-xi)/n;
        double res = 0;
        for(int i=0; i < n; ++i){
            double xi_aux = xi + delta * i;
        
            res += legendre(numOfPoints, xi_aux, xi_aux + delta);
            
        }
        prev = curr;
        curr = res;
    }
    cout << "Resultado: " <<  curr << endl;
    cout << "Partições: " << n << endl;
    cout << "Número de iterações: " << log2(n) << endl;
  

    return 0;
}