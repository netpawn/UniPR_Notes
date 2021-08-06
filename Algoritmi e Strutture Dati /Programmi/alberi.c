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

struct nodo *crea_albero() {
    struct nodo *radice;
    
    radice = malloc(sizeof(struct nodo));
    
    radice = nuovoNodo(1);
    
    radice->sx = nuovoNodo(2);
    radice->dx = nuovoNodo(3);
    
    radice->sx->sx = nuovoNodo(4);
    radice->sx->dx = nuovoNodo(5);
    radice->dx->sx = nuovoNodo(6);
    radice->dx->dx = nuovoNodo(7);
    
    return radice;
}

void stampa_anticipato(struct nodo *n) {

    if (n != NULL) {
        printf("%d\n", n->valore);
        stampa_anticipato(n->sx);
        stampa_anticipato(n->dx);
    }
}

void stampa_simmetrico(struct nodo *n) {
    
    if (n != NULL) {
        stampa_simmetrico(n->sx);
        printf("%d\n", n->valore);
        stampa_simmetrico(n->dx);
    }
    
}

void stampa_posticipato(struct nodo *n) {
    
    if (n != NULL) {
        stampa_posticipato(n->sx);
        stampa_posticipato(n->dx);
        printf("%d\n", n->valore);
    }
}

struct nodo *cerca_anticipato(struct nodo *n, int valore) {
    struct nodo *risultato;
    
    if (n == NULL || n->valore == valore)
        risultato = n;
    else {
        risultato = cerca_anticipato(n->sx, valore);
        if (risultato == NULL)
            risultato = cerca_anticipato(n->dx, valore);
    }
    
    return risultato;
}

int main() {
    struct nodo *radice;
    struct nodo *n;
    int k;
    
    radice = crea_albero();
    
    printf("Stampa con visita in ordine anticipato\n");
    stampa_anticipato(radice);
    
    printf("Stampa con visita in ordine simmetrico\n");
    stampa_simmetrico(radice);
    
    printf("Stampa con visita in ordine posticipato\n");
    stampa_posticipato(radice);
    
    printf("\nQuale valore vuoi cercare?\n");
    scanf("%d",&k);
    
    n = cerca_anticipato(radice,k);
    if (n != NULL)
        printf("Ho trovato il valore %d\n",n->valore);
    else
        printf("Valore non trovato!\n");
    
    return 0;
}
 