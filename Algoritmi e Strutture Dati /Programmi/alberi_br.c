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
    
    radice = nuovoNodo(4);
    
    radice->sx = nuovoNodo(2);
    radice->dx = nuovoNodo(6);
    
    radice->sx->sx = nuovoNodo(1);
    radice->sx->dx = nuovoNodo(3);
    radice->dx->sx = nuovoNodo(5);
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


struct nodo *cerca_ABR(struct nodo *n, int valore) {
    struct nodo *risultato;
    
    risultato = n;
    
    //printf("*** %d\n", risultato->valore);
    
    while (risultato != NULL && risultato->valore != valore) {
        if (valore < risultato->valore)
            risultato = risultato->sx;
        else
            risultato = risultato->dx;
        
        //printf("*** %d\n", risultato->valore);
    }
    
    return risultato;
}

bool inserisci_ABR(struct nodo **radice, int valore) {
    bool inserito;
    struct nodo *n, *padre, *nuovo;
    
    n = *radice;
    padre = *radice;
    
    while(n != NULL && n->valore != valore) {
 
        padre = n;
        
        if (valore < n->valore)
            n = n->sx;
        else
            n = n->dx;
    }
        
    if (n != NULL)
         inserito = false;
    else {
        nuovo = malloc(sizeof(struct nodo));
        
        nuovo->valore = valore;
        nuovo->sx = NULL;
        nuovo->dx = NULL;
        
        if (n == *radice)
            *radice = nuovo;
        else
            if (valore < padre->valore)
                padre->sx = nuovo;
            else
                padre->dx = nuovo;
        
        inserito = true;
    }
    
    return inserito;
}

bool rimuovi_ABR(struct nodo **radice, int valore) {
    bool rimosso;
    struct nodo *n, *padre, *sost;
    
    n = *radice;
    
    while(n != NULL && n->valore != valore) {
        padre = n;
        if (valore < n->valore)
            n = n->sx;
        else
            n = n->dx;
    }
    
    if (n == NULL)
        rimosso = false;
    else {
        rimosso = true;
            if (n->sx == NULL) {
                if (n == *radice)
                    *radice = n->dx;
                else if (valore < padre->valore)
                    padre->sx = n->dx;
                else
                    padre->dx = n->dx;
            }
            else if (n->dx == NULL) {
                if (n == *radice)
                    *radice = n->sx;
                else if (valore < padre->valore)
                    padre->sx = n->sx;
                else
                    padre->dx = n->sx;
            }
            else {
                sost = n;
                padre = sost;
                n = sost->sx;
                
                while(n->dx != NULL) {
                    padre = n;
                    n = n->dx;
                }
                
                sost->valore = n->valore;
                if (padre == sost)
                    padre->sx = n->sx;
                else
                    padre->dx = n->sx;
            }
        
            free(n);
        }
    
    return rimosso;
}

int main() {
    struct nodo *radice;
    struct nodo *n;
    int k;
    
    radice = crea_albero();
    
    printf("\nQuale valore vuoi cercare?\n");
    scanf("%d",&k);
    
    n = cerca_ABR(radice,k);
    if (n != NULL)
        printf("Ho trovato il valore %d\n",n->valore);
    else
        printf("Valore non trovato!\n");
   
    printf("\n*** *** *** *** *** *** *** *** *** ***\n");
    
    printf("\nQuale valore vuoi inserire?\n");
    scanf("%d",&k);
    
    bool b = inserisci_ABR(&radice, k);
    
    if (b)
        printf("Ho inserito il valore %d\n", k);
    else
        printf("Il valore %d era già presente nell'albero\n", k);
    
    stampa_anticipato(radice);
    
    printf("\n*** *** *** *** *** *** *** *** *** ***\n");
    
    printf("\nQuale valore vuoi rimuovere?\n");
    scanf("%d",&k);
    
    b = rimuovi_ABR(&radice, k);
    
    if (b)
        printf("Ho rimosso il valore %d\n", k);
    else
        printf("Il valore %d non era presente nell'albero\n", k);
    
    stampa_anticipato(radice);
    
    
    return 0;
}
 