#include <stdio.h>
#include <stdbool.h>
#include <time.h>


void bubblesort(int v[], int n) {
    int temp;

    for (int i = 1; i < n; i++)
        for (int j = n - 1; j >= i; j--)
            if (v[j] < v[j - 1]) {
                temp = v[j - 1];
                v[j - 1] = v[j];
                v[j] = temp;
            }
}
        

int main() {
    int n = 10;
    int v[] = {8, 4, 5, 10, 2, 1, 3, 9, 7, 6};
    
    bubblesort(v,n);
    
    for (int i = 0; i < n; i++)
        printf("%d ",v[i]);
    
    printf("\n");
    
    return 0;
}
