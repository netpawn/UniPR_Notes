#include "risorsa_no_exc.hh"

/*
void codice_utente(){
    Risorsa* r1 = acquisisci_risorsa(); 
    usa_risorsa(r1); 
    Risorsa* r2 = acquisisci_risorsa(); 
    usa_risorse(r1, r2); 
    Risorsa* r3 = acquisisci_risorsa(); 
    usa_risorse(r1, r3); 
    restituisci_risorsa(r3); 
    restituisci_risorsa(r1); 
}
*/



/*
bool codice_utente(){
     Risorsa* r1 = acquisisci_risorsa(); 
     if(r1==nullptr){ //err durante acquisizione r1
     return true; 
    }

    if(usa_risorsa(r1)){
        //errore durante uso, rilascio r1
        restituisci_risorsa(r1); 
        return true; 
    } 
    Risorsa* r2 = acquisisci_risorsa(); 
        if(r1==nullptr){ //err durante acquisizione r1
        restituisci_risorsa(r1); 
        return true;
    } 
    //fine uso r2 rilascio 
    restituisci_risorsa(r2); 
    //ho ancora r1 e va rilasciata 

    Risorsa* r3 = acquisisci_risorsa(); 
        if(r3==nullptr){
        //errore acquisizione r3 rilascio r1
        restituisci_risorsa(r1);
    }
    
    //acquisita r3 dopo devo rilasciare r1 e r2 

    if(usa_risorse(r1, r3)){
        //errore durante l'uso delle due 
        restituisci_risorsa(r3);
        restituisci_risorsa(r1);
        return true; 
    }

    //fine uso r3 e r1 le rilascio 
    restituisci_risorsa(r3);
    restituisci_risorsa(r1);

    //tutto ok
    return false; 

*/

void codice_utente(){

    Risorsa* r1 = acquisisci_risorsa(); 
    try{
    usa_risorsa(r1); 
    Risorsa* r2 = acquisisci_risorsa(); 

    try{
    usa_risorse(r1, r2); 
    restituisci_risorsa(r2);
    }catch(...){
        restituisci_risorsa(r2);
        throw; 
    }
    
    Risorsa* r3 = acquisisci_risorsa();
    try{ 
    usa_risorse(r1, r3); 
    restituisci_risorsa(r3); 
    restituisci_risorsa(r1); 
    }catch(...){
        restituisci_risorsa(r3); 
        throw; 
    }
    }catch(...){
        restituisci_risorsa(r1); 
        throw; 
    }
    
} 

/*
NOTE: 

1) si crea un blocco try catch per ogni risorsa
2) il blocco si apre subito dopo la sua acquisizione, non prima 
3) il blocco deve proteggere quella particolare risorsa
4) al termine del blocco prima del catch va effettuata la restituzione
5) quando c'è (...) nel catch vuol dire che catturiamo tutto 
6) nel catch dobbiamo fare due cose:
rilasciare e rilanciare l'eccezione







*/