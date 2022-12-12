#include <iostream>
#include <math.h>
// #define EPSILON 0.01
using namespace std;


double x_s_simple(double a, double b, double s){
    return (a + b)/2.0 + ((b - a)/2.0) * tanh(s);
}

double dx_s_simple(double a, double b, double s){
    return (b - a)/2.0 * (1.0/pow(cosh(s), 2));
}

double x_s_double(double a, double b, double s){
    return (a + b)/2.0 + (b - a)/2.0 * tanh(M_PI/2 * sinh(s));
}

double dx_s_double(double a, double b, double s){
    return (b - a)/2.0 * ((M_PI/2.0) * cosh(s)/pow(cosh(M_PI/2.0 * sinh(s)) ,2));
}

double simpleExponential(double (*f)(double), double a, double b, double s){
    return f(x_s_simple(a, b, s)) * dx_s_simple(a, b, s); 
}

double doubleExponential(double (*f)(double), double a, double b, double s){
    return f(x_s_double(a, b, s)) * dx_s_double(a, b, s); 
}

double f_x(double x){
    return 1.0 / sqrt(x);
}

double f_x_simple_exponential(double x){
    return simpleExponential(&f_x, 0, 1, x);
}

double f_x_double_exponential(double x){
    return doubleExponential(&f_x, 0, 1, x);
}

// primeiro exemplo da lista #14
double g_x(double x){
    return 1.0 / cbrt(pow(x, 2));
}
double g_x_simple_exponential(double x){
    return simpleExponential(&g_x, -1, 1, x);
}
double g_x_double_exponential(double x){
    return doubleExponential(&g_x, -1, 1, x);
}

// segundo exemplo da lista #14
double h_x(double x){
    return 1.0 / sqrt(4 - pow(x, 2)); 
}

double h_x_simple_exponential(double x){
    return simpleExponential(&h_x, -2, 0, x);
}

double h_x_double_exponential(double x){
    return doubleExponential(&h_x, -2, 0, x);
}

double x(double xi, double xf, double alpha){
    return (xi+xf)/2.0 + ((xf-xi)/2.0)*alpha;
}

double legendre(double (*f)(double), int numOfPoints, double xi, double xf, double EPSILON){
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

    double curr = 0;
    double prev = -INFINITY;
    int n = 1;

    while(abs(curr - prev) > EPSILON){
        n *= 2;
        double delta = (xf-xi)/n;
        double finalRes = 0;
        for(int i=0; i < n; ++i){
            double xi_aux = xi + delta * i;
            double tempRes = 0;
            for(int i=0; i < numOfPoints; ++i)  tempRes += f(x(xi_aux, xi_aux + delta, alpha[i])) * w[i];
            tempRes *= ((xi_aux + delta)-xi_aux)/2.0;
            finalRes += tempRes;
            
        }
        prev = curr;
        curr = finalRes;
    }
    return curr;



    double tempRes = 0;
    for(int i=0; i < numOfPoints; ++i)  tempRes += f(x(xi, xf, alpha[i])) * w[i];
    tempRes *= (xf-xi)/2.0;
    return tempRes;
    
}

double openNewtonCotes(double (*f)(double), int numOfPoints, double xi, double xf){
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
    double c = 0;
    double xi = -c, xf = c;
    int numOfPoints = 4;
    double (*f)(double) = &g_x_simple_exponential;
    double EPSILON = 0.01;
    double cError = 0.001;

    double prevCRes = -INFINITY;
    double currCRes = 0;
    
    while( !isnan(currCRes) && isfinite(currCRes) && abs(currCRes - prevCRes) > cError){
        prevCRes = currCRes;
        c += 1;
        xi = -c, xf = c;
        currCRes = legendre(&(*f), numOfPoints, xi, xf, EPSILON);
    }

    cout << "Resultado = " << prevCRes << ", para c = " << c-1 << endl;


    return 0;
}