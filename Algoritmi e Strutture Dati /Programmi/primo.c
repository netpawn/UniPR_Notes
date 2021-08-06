#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool primo(int n){
    
    for (int i = 2; i <= sqrt(n); i++)
        if (n%i == 0)
            return false;
    
    return true;
}

int main () {
    
    int n = 10;
    bool b;
    
    b = primo(n);
    
    if (b == 0)
        printf("Il numero non è primo \n");
    else
        printf("Il numero è primo \n");
}

