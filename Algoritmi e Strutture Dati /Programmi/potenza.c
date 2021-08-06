#include <stdio.h>

double potenza1(double x, int n){
    
    double z = 1.0;
    int i = 1;
    
    if (n < 0) {
        printf("Errore!\n");
        return 0;
    }
    
    while (i <= n) {
        z = z * x;
        i++;
    }
    
    return z;
}

double potenza2(double x, int n){
    
    double z = 1.0;
    
    if (n < 0) {
        printf("Errore!\n");
        return 0;
    }
 
    while (n != 0){
        if (n&1)
            z = z*x;

        x = x*x;
        
        n = n/2;
    }

    return z;
}

int main () {
    
    double x = 2;
    int n = 15;
    double p1, p2;
    
    p1 = potenza1(x,n);
    printf("%f \n",p1);
    
    p2 = potenza2(x,n);
    printf("%f \n",p2);
}

