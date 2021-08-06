#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct nodo {
    int valore;
    struct nodo *sx, *dx;
};

struct nodo *nuovoNodo(int valore) {
    struct nodo *n;
    
    n = malloc(sizeof(struct nodo));
    
    n->valore = valore;
    n->sx = NULL;
    n->dx = NULL;
    
    return n;
}

struct nodo *crea_albero1() {
    struct nodo *radice;
    
    radice = malloc(sizeof(struct nodo));
    
    radice = nuovoNodo(4);
    
    radice->sx = nuovoNodo(2);
    radice->dx = nuovoNodo(6);
    
    radice->sx->sx = nuovoNodo(1);
    radice->sx->dx = nuovoNodo(3);
    radice->dx->sx = nuovoNodo(5);
    radice->dx->dx = nuovoNodo(7);
    
    return radice;
}

struct nodo *crea_albero2() {
    struct nodo *radice;
    
    radice = malloc(sizeof(struct nodo));
    
    radice = nuovoNodo(4);
    
    radice->sx = nuovoNodo(2);
    radice->dx = nuovoNodo(6);
    
    radice->sx->sx = nuovoNodo(1);
    radice->sx->sx->sx = nuovoNodo(-1);
    
    return radice;
}

struct nodo *crea_albero3() {
    struct nodo *radice;
    
    radice = malloc(sizeof(struct nodo));
    
    radice = nuovoNodo(4);
    
    radice->sx = nuovoNodo(2);
    radice->dx = nuovoNodo(6);
    
    radice->sx->sx = nuovoNodo(1);
    radice->sx->dx = nuovoNodo(3);
    radice->sx->sx->sx = nuovoNodo(-1);
    
    return radice;
}

struct nodo *crea_albero4() {
    struct nodo *radice;
    
    radice = malloc(sizeof(struct nodo));
    
    radice = nuovoNodo(4);
    
    radice->sx = nuovoNodo(2);
    radice->dx = nuovoNodo(6);
    
    radice->sx->sx = nuovoNodo(1);
    radice->sx->dx = nuovoNodo(3);
    radice->sx->sx->sx = nuovoNodo(-1);
    
    radice->dx->sx = nuovoNodo(5);
    
    return radice;
}

int altezza(struct nodo *radice) {
    
    if (radice == NULL || (radice->sx == NULL && radice->dx == NULL) )
        return 0;
    else {
        int hs = altezza(radice->sx);
        int hd = altezza(radice->dx);
        
        if (hs > hd)
            return hs+1;
        else
            return hd+1;
    }

}

bool bilanciato(struct nodo *radice) {
    int hs;
    int hd;
    
    // albero vuoto
    if (radice == NULL)
        return true;
    
    hs = altezza(radice->sx);
    hd = altezza(radice->dx);
    
    if (abs(hs - hd) <= 1 && bilanciato(radice->sx) && bilanciato(radice->dx))
        return true;
    
    return false;
}

struct nodo *ruota(struct nodo *radice) {
    struct nodo *x = radice->sx;
    struct nodo *T2 = x->dx;
    
    x->dx = radice;
    radice->sx = T2;
    
    return x;
}

void stampa_anticipato(struct nodo *n) {

    if (n != NULL) {
        printf("%d\n", n->valore);
        stampa_anticipato(n->sx);
        stampa_anticipato(n->dx);
    }
}

int main() {
    struct nodo *radice;
    struct nodo *n;
    int k;
    
    radice = crea_albero3();

    printf("\nL'altezza dell'albero è %d\n", altezza(radice));
    
    bool b = bilanciato(radice);
    
    if (b)
        printf("L'albero è AVL\n");
    else
        printf("L'albero NON è AVL\n");
    
    stampa_anticipato(radice);
    
    
    n = ruota(radice);
    
    b = bilanciato(n);
    
    if (b)
        printf("L'albero è AVL\n");
    else
        printf("L'albero NON è AVL\n");
    
    stampa_anticipato(n);
    
    
    return 0;
}
 