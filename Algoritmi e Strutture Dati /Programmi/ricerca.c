#include <stdio.h>
#include <stdbool.h>
#include <time.h>

bool ricerca_lineare_ricorsiva(int v[], int k, int n) {
    
    if (n == 1) {
        if (v[n-1] == k)
            return true;
        else
            return false;
    }
    
    if (v[n-1] == k)
        return true;
    else
        return ricerca_lineare_ricorsiva(v,k,n-1);
    
}

bool ricerca_dicotomica_ricorsiva(int v[], int k, int primo, int ultimo) {
    
    int med=(primo + ultimo)/2;
    
    if (primo == ultimo) {
        if (v[primo] == k)
            return true;
        else
            return false;
    }
    
    if (v[med] == k)
        return true;
    else {
        if (v[med] < k)
            return ricerca_dicotomica_ricorsiva(v, k, med+1, ultimo);
        else
            return ricerca_dicotomica_ricorsiva(v, k, primo, med-1);
    }
    
}

int main() {
    int k, i;
    int len = 100;
    int v[len];
    bool b1, b2;
    
    // inizializzazione del vettore
    for(i=0;i<len;i++)
        v[i]=2*(i+1);
    
    printf("Inserisci un numero: \n");
    
    scanf("%d",&k);
    
    b1 = ricerca_lineare_ricorsiva(v,k,len);

    b2 = ricerca_dicotomica_ricorsiva(v,k,0,len-1);
    
    if (b2)
        printf("Valore trovato\n");
    else
        printf("Valore NON trovato\n");

    return 0;
}
