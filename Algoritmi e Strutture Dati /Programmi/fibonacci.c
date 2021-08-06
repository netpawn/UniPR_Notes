#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int fibonacci_2 (int n) {
    
    if (n <= 0)
        return -1;
    else if (n <= 2)
        return 1;
    else
        return fibonacci_2(n-1) + fibonacci_2(n-2);
    
}

int main() {
    
    int n;
    
    printf ("Dammi il valore di n: ");
    
    scanf("%d", &n);
    
    printf ("Il %d numero di Fibonacci vale:  %d \n", n, fibonacci_2(n));

    return 0;
}

