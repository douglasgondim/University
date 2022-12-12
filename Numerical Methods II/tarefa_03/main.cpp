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

double closedNewtonCotes(int numOfPoints, double xi, double xf){
    double h;
    switch (numOfPoints)
    {
    case 2:
        return ((xf - xi)/2) * (f(xi) + f(xf));
        break;
    case 3:
        h = (xf-xi)/2;
        return (h/3) * (f(xi) + 4 * f(xi + h) + f(xf));
        break; 
    case 4:
        h = (xf-xi)/3;
        return ((3*h)/8) * (f(xi) + 3 * f(xi + h) + 3 * f(xi + 2*h) + f(xf));
        break;
    case 5:
        h = (xf-xi)/4;
        return (2.0/45) * h * (7*f(xi) + 32*f(xi + h) + 12 * f(xi + 2*h) + 32 * f(xi + 3*h) + 7 * f(xf));
        break;
    default:
        break;
    }
    return -1.0;
}

double openNewtonCotes(int numOfPoints, double xi, double xf){
    double h;
    switch (numOfPoints){
    case 2:
        h = (xf - xi)/3;
        return ((xf - xi)/2) * (f(xi + h) + f(xi + 2*h));
        break;
    case 3:
        h = (xf - xi)/4;
        return ((4*h)/3) * (2*f(xi + h) - f(xi + 2*h) + 2*f(xi + 3*h));
        break;
    case 4:
        h = (xf - xi)/5;
        return ((5*h)/24) * (11*f(xi + h) + f(xi + 2*h) + f(xi + 3*h) + 11 * f(xi + 4*h));
        break; 
    case 5:
        h = (xf - xi)/6;
        return (6.0/20) * h * (11*f(xi + h) - 14 * f(xi + 2*h) + 26*f(xi + 3*h) - 14*f(xi + 4*h) + 11*f(xi + 5*h));
        break;
    
    default:
        break;
    }
    return -1.0;


}

int main(){
    int numOfPoints, formulaType;
    double xf, xi, EPSILON;

    cout << "Digite o número de pontos: ";
    cin >> numOfPoints;

    // cout << "Digite o limite inferior: ";
    // cin >> xi;
    xi = 0;

    // cout << "Digite o limite superior: ";
    // cin >> xf;

    xf = M_PI;
    cout << "Digite [1] para fórmula fechada ou [2] para fórmula aberta: ";
    cin >> formulaType;

    cout << "Digite o Erro esperado: ";
    cin >> EPSILON;



    double curr;

    if(formulaType == 1){
        curr =  closedNewtonCotes(numOfPoints, xi, xf);
    }else{
        curr =  openNewtonCotes(numOfPoints, xi, xf);
    }

    double prev = -INFINITY;
    int n = 1; 

    while(abs(curr - prev) > EPSILON){
        n *= 2;
        double delta = (xf-xi)/n;
        double res = 0;
        for(int i=0; i < n; ++i){
            double xi_aux = xi + delta * i;
            if(formulaType == 1){
                res += closedNewtonCotes(numOfPoints, xi_aux, xi_aux + delta);
            }else{
                res += openNewtonCotes(numOfPoints, xi_aux, xi_aux + delta);
            }
        }
        prev = curr;
        curr = res;
    }
    cout << "Resultado: " <<  curr << endl;
    cout << "Partições: " << n << endl;
    cout << "Número de iterações: " << log2(n) << endl;
    

    return 0;
}