#include <stdio.h>

int somma(int n){
    
    if (n <= 0)
        return 0;
    
    if (n == 1)
        return 1;
    else
        return n + somma(n-1);
    
}

int main () {
    
    int n = 10;
    int s;
    
    s = somma(n);
    printf("La somma vale: %d \n",s);
        
}

