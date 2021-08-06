#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


void merge(int v[], int sx, int mx, int dx) {
    int i = sx;
    int j = mx + 1;
    int k = 0;
    int *b;
 
    b = (int *)calloc(dx + 1, sizeof(int));
 
    while (i <= mx && j <= dx) {
        if (v[i] < v[j]) {
            b[k] = v[i];
            i++;
        }
        else {
            b[k] = v[j];
            j++;
        }
        k++;
    }
 
    while (i <= mx) {
        b[k] = v[i];
        i++;
        k++;
    }
 
    while (j <= dx) {
        b[k] = v[j];
        j++;
        k++;
    }
 
    for (k = sx; k <= dx; k++)
        v[k] = b[k-sx];
 
    free(b);
     
    return;
 }

void merge_sort(int v[], int sx, int dx) {
    int mx;
    
    if (sx < dx) {
        
        mx = (sx + dx) / 2;
        
        merge_sort(v, sx, mx);
        merge_sort(v, mx + 1, dx);
        
        merge(v, sx, mx, dx);
    }
}

int main() {
    int n = 10;
    int v[] = {8, 4, 5, 10, 2, 1, 3, 9, 7, 6};
    
    merge_sort(v,0,n-1);
    
    for (int i = 0; i < n; i++)
        printf("%d ",v[i]);
    
    printf("\n");
    
    return 0;
}