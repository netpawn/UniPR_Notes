#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct elemento {
    int valore;
    struct elemento *successivo;
};
 
struct elemento_dc {
    int valore;
    struct elemento_dc *successivo, *precedente;
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

bool cerca(struct elemento *testa, int valore) {
    struct elemento *e;
    
    e = testa;
    while (e != NULL) {
        if(valore == e->valore)
            return true;
        else
            e = e->successivo;
    }
    
    return false;
}

int inserisci_in_lista_ordinata(struct elemento **testa, int valore) {
    int inserito;
    struct elemento *corrente, *precedente, *nuovo;
    
    corrente = *testa;
    precedente = *testa;
    
    while(corrente != NULL && corrente->valore < valore) {
        precedente = corrente;
        corrente = corrente->successivo;
    }
    
    if (corrente != NULL && corrente->valore == valore)
        inserito = 0;
    else {
        inserito = 1;
        nuovo = malloc(sizeof(struct elemento));
        nuovo->valore = valore;
        nuovo->successivo = corrente;
        
        if (corrente == *testa)
            *testa = nuovo;
        else
            precedente->successivo = nuovo;
    }
    
    return inserito;
}



int rimuovi_da_lista_ordinata(struct elemento **testa, int valore){
    int rimosso;
    struct elemento *corrente, *precedente;
    
    corrente = *testa;
    precedente = *testa;
    
    while(corrente != NULL && corrente->valore < valore) {
        precedente = corrente;
        corrente = corrente->successivo;
    }
    
    if (corrente == NULL || corrente->valore > valore)
        rimosso = 0;
    else {
        rimosso = 1;
        
        if (corrente == *testa)
            *testa = corrente->successivo;
        else
            precedente->successivo = corrente->successivo;
        
        free(corrente);
    }
    
    return rimosso;
}




int main() {
    int a, b, n;
    struct elemento *lista;
    
    lista = crea_lista(); /* crea la lista */
    stampa_lista(lista);
    
    // *** RICERCA ***
    printf("** Dammi un elmento da cercare **\n");
    scanf("%d", &n);
    
    if(cerca(lista, n))
        printf("** Elemento Trovato ** \n");
    else
        printf("** Elemento NON Trovato ** \n");
    
    // *** INSERIMENTO ***
    printf("** Dammi un elmento da inserire **\n");
    scanf("%d", &n);
    
    a = inserisci_in_lista_ordinata(&lista, n);
    stampa_lista(lista);
    
    // *** RIMOZIONE ***
    printf("** Dammi un elmento da rimuovere **\n");
    scanf("%d", &n);
    
    b = rimuovi_da_lista_ordinata(&lista, n);
    stampa_lista(lista);
    
    return 0;
}
 