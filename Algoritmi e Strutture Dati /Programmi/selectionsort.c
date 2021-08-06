#include <stdio.h>
#include <stdbool.h>

void selectionsort(int v[], int n) {
    int min;
    int i_min;
    
    for (int i = 0; i < n - 1; i++) {
        min = v[i];
        i_min = i;
        
        for (int j = i + 1; j < n; j++)
            if (v[j] < min) {
                min = v[j];
                i_min = j;
            }
        
        if (i_min != i) {
            v[i_min] = v[i];
            v[i] = min;
        }
    }
}

int main() {
    int n = 10;
    int v[] = {8, 4, 5, 10, 2, 1, 3, 9, 7, 6};
    
    selectionsort(v,n);
    
    for (int i = 0; i < n; i++)
        printf("%d ",v[i]);
    
    printf("\n");
    
    return 0;
}
