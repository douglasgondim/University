#include <iostream>
#include "math.h"
#include <limits>
using namespace std;

double f(double x){
    return pow(sin(2*x) + 4*pow(x, 2) + 3*x, 2);
}

double x(double xi, double xf, double alpha){
    return (xi+xf)/2.0 + ((xf-xi)/2.0)*alpha;
}

double hermite(int numOfPoints){
    double *alpha = new double[numOfPoints];
    double *w = new double[numOfPoints];

    switch (numOfPoints){
        case 2:
            alpha[0] = -1.0/sqrt(2);
            alpha[1] = 1.0/sqrt(2);

            w[0] = sqrt(M_PI)/2;
            w[1] = w[0];
            break;
        case 3:
            alpha[0] = -sqrt(3.0/2);
            alpha[1] = 0;
            alpha[2] = sqrt(3.0/2);

            w[0] = sqrt(M_PI)/6;
            w[1] = 2*sqrt(M_PI)/3;
            w[2] = w[0];
            break;
        case 4:
            alpha[0] = -sqrt(3.0/2 - sqrt(3.0/2));
            alpha[1] = -sqrt(3.0/2 + sqrt(3.0/2));
            alpha[2] =  sqrt(3.0/2 - sqrt(3.0/2));
            alpha[3] =  sqrt(3.0/2 + sqrt(3.0/2));
          

            w[0] = 0.804914;
            w[1] = 0.0813128;
            w[2] = w[0];
            w[3] = w[1];
            break;

        default:{
            return -1;
        }
        
    }

    double res = 0;
    for(int i=0; i < numOfPoints; ++i) res += f(alpha[i]) * w[i];
    return res;
    
}

double laguerre(int numOfPoints){
    double *alpha = new double[numOfPoints];
    double *w = new double[numOfPoints];

    switch (numOfPoints){
        case 2:
            alpha[0] = 2 - sqrt(2);
            alpha[1] = 2 + sqrt(2);

            w[0] = (2 + sqrt(2))/4;
            w[1] = (2 - sqrt(2))/4;
            break;
        case 3:
            alpha[0] = 0.4157745568;
            alpha[1] = 2.2942803603;
            alpha[2] = 6.2899450829;

            w[0] = 0.7110930099;
            w[1] = 0.2785177336;
            w[2] = 0.0103892565;
            break;
        case 4:
            alpha[0] = 0.32255;
            alpha[1] = 1.7458;
            alpha[2] = 4.5366;
            alpha[3] = 9.39507;
          

            w[0] = 0.603154;
            w[1] = 0.357419;
            w[2] = 0.0388879;
            w[3] = 0.000539295;
            break;

        default:{
            return -1;
        }
        
    }

    double res = 0;
    for(int i=0; i < numOfPoints; ++i) res += f(alpha[i]) * w[i];
    return res;
    
}

double chebyshev(int numOfPoints){
    double *alpha = new double[numOfPoints];
    double *w = new double[numOfPoints];

    switch (numOfPoints){
        case 2:
            alpha[0] = -sqrt(2)/2;
            alpha[1] = sqrt(2)/2;

            w[0] = M_PI/2;
            w[1] = w[0];
            break;
        case 3:
            alpha[0] = -sqrt(3.0)/2;
            alpha[1] = 0;
            alpha[2] = sqrt(3.0)/2;

            w[0] = M_PI/3;
            w[1] = w[2] = w[0];
            break;
        case 4:
            alpha[0] = - (sqrt(2 - sqrt(2)))/2;
            alpha[1] = - (sqrt(2 + sqrt(2)))/2;
            alpha[2] =   (sqrt(2 - sqrt(2)))/2;
            alpha[3] =   (sqrt(2 + sqrt(2)))/2;
          

            w[0] = M_PI/4;
            w[1] = w[2] = w[3] = w[0];
            break;

        default:{
            return -1;
        }
        
    }

    double res = 0;
    for(int i=0; i < numOfPoints; ++i) res += f(alpha[i]) * w[i];
    return res;
    
}

int main(){
    int numOfPoints, integrationType;
    cout << "Cáculo de integração de Gauss [Hermite, Laguerre e Chebyshevy]" << endl << endl;

    cout << "Digite [1] para Hermite, [2] para Laguerre ou [3] para Chebyshev: ";
    cin >> integrationType;

    cout << "Digite o número de pontos: ";
    cin >> numOfPoints;

    double res;

    switch (integrationType){
    case 1:
        res = hermite(numOfPoints);
        break;
    case 2:
        res = laguerre(numOfPoints);
        break;
    case 3:
        res = chebyshev(numOfPoints);
        break;
    default:
        res = -1;
        break;
    }

    cout << "Resultado: " << res << endl;

    return 0;
}