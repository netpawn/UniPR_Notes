#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
typedef struct _elemento {
    int valore;
    struct _elemento *successivo;
} elemento;
*/

struct elemento {
    int valore;
    struct elemento *successivo;
};

struct elemento *crea_lista() {
    
    struct elemento *p, *punt;
    int i, n;
    
    printf("\n Specificare il numero di elementi... ");
    scanf("%d", &n);
    
    if(n == 0)
        p = NULL;
    else {
        /* creazione primo elemento */
        p = malloc(sizeof(struct elemento));
        
        printf("\nInserisci il primo valore: ");
        scanf("%d", &p->valore);
        
        punt = p;
        
        for(i = 2; i <= n; i++) {
            punt->successivo = malloc(sizeof(struct elemento));
            punt = punt->successivo;
            
            printf("\nInserisci il %d elemento: ", i);
            scanf("%d", &punt->valore);
        }
        
        punt->successivo = NULL; // marcatore fine lista
    }
    return p;
}

void stampa_lista(struct elemento *testa) {
    struct elemento *e;
    
    printf("\n lista ---> ");
    
    for (e = testa; e != NULL; e = e->successivo) {
        printf("%d   ", e->valore);
    }
    
    printf("\n");
}

struct elemento *ultimo(struct elemento *testa) {
    struct elemento *e;
    e = testa;
    
    while(e->successivo != NULL)
        e = e->successivo;

    return e;
}

void metti_in_coda(struct elemento **uscita, struct elemento **ingresso, int valore) {
    
    struct elemento *nuovo;
    
    nuovo = malloc(sizeof(struct elemento));
    nuovo->valore = valore;
    nuovo->successivo = NULL;
    
    if (*ingresso != NULL)
        (*ingresso)->successivo = nuovo;
    else
        *uscita = nuovo;
    
    *ingresso = nuovo;
}

struct elemento *togli_da_coda(struct elemento **uscita, struct elemento **ingresso) {
    
    struct elemento *e;
    
    e = *uscita;
    
    if (*uscita != NULL) {
        *uscita = (*uscita)->successivo;
        if (*uscita == NULL)
            *ingresso = NULL;
    }
    
    return e ;
}

void metti_su_pila(struct elemento **cima, int valore) {
    struct elemento *nuovo;
    
    nuovo = malloc(sizeof(struct elemento));
    nuovo->valore = valore;
    nuovo->successivo = *cima;
    
    *cima = nuovo;
}

struct elemento *togli_da_pila(struct elemento **cima) {
    struct elemento *e;
    e = *cima;
    
    if (*cima != NULL)
        *cima = (*cima)->successivo;
    
    return e;
}
 
int main() {
    int a, b, n;
    struct elemento *lista;
    struct elemento *lista1;
    struct elemento *ingresso;
    
    lista = crea_lista(); /* crea la lista */
    stampa_lista(lista);
    
    ingresso = ultimo(lista);
    n = 3;
    printf("\n** Aggiungo %d alla coda **\n", n);
    metti_in_coda(&lista, &ingresso, n);
    printf("La coda aggiornata è: ");
    stampa_lista(lista);
   
    ingresso = ultimo(lista);
    printf("\n** Tolgo un elemento dalla coda **\n");
    lista1 = togli_da_coda(&lista, &ingresso);
    printf("L'elemento rimosso è: %d\n", lista1->valore);
    printf("La coda aggiornata è: ");
    stampa_lista(lista);
  
    printf("*** *** ***\n");
    
    lista = crea_lista(); /* crea la lista */
    stampa_lista(lista);
    
    n = 7;
    printf("\n** Aggiungo %d alla pila **\n", n);
    metti_su_pila(&lista, n);
    printf("La pila aggiornata è: ");
    stampa_lista(lista);
    
    printf("\n** Tolgo un elemento dalla pila **\n");
    lista1 = togli_da_pila(&lista);
    printf("La pila aggiornata è: ");
    stampa_lista(lista);

    return 0;
}