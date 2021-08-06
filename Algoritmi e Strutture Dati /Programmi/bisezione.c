#include <stdio.h>
#include <stdbool.h>
#include <math.h>

double delta=1e-6;
double epsilon=1e-9;

double f(double x) {
    return x*x-2;
}

double bisezione(double a, double b) {
    double xmedio, ymedio;
    
    while(fabs(b-a)>delta) {
        xmedio=(a+b)/2;
        ymedio=f(xmedio);
        
        if (fabs(ymedio)<epsilon)
            return xmedio;
        
        if (ymedio*f(a)<0)
            b=xmedio;
        else
            a=xmedio;
    }
    
    return xmedio;
}

int main() {
    double a=0.0, b=2.0;

    printf("%s %f\n","La soluzione vale: ", bisezione(a,b));

    return 0;
}
