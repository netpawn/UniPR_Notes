#include <stdio.h>
#include <stdbool.h>
#include <time.h>


void quick_sort(int v[], int sx, int dx) {
    int pivot = v[(sx + dx) / 2]; // v[3] = 7
    int i = sx; // i = 4
    int j = dx; // j = 3
    int temp;
    
    while (i <= j) {
        while (v[i] < pivot)
            i++;
        while (v[j] > pivot)
            j--;
        if (i <= j) {
            if (i < j) {
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
            i++;
            j--;
        }
    }

    if (sx < j)
        quick_sort(v, sx, j);
    
    if (i < dx)
        quick_sort(v, i, dx);
}
        

int main() {
    int n = 10;
    int v[] = {8, 4, 5, 10, 2, 1, 3, 9, 7, 6};
    
    quick_sort(v,0,n-1);
    
    for (int i = 0; i < n; i++)
        printf("%d ",v[i]);
    
    printf("\n");
    
    return 0;
}