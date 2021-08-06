#include <stdio.h>
#include <stdbool.h>

void insertionsort(int v[], int n) {
    int temp;
    int j;
    
    for (int i = 1; i < n; i++) {
        
        temp = v[i];
        
        for(j = i-1; (j >= 0) && (v[j] > temp); j--)
            v[j + 1] = v[j];
        
        if (j != i-1)
            v[j + 1] = temp;
    }
}

int main() {
    int n = 10;
    int v[] = {8, 4, 5, 10, 2, 1, 3, 9, 7, 6};
    
    insertionsort(v,n);
    
    for (int i = 0; i < n; i++)
        printf("%d ",v[i]);
    
    printf("\n");
    
    return 0;
}
