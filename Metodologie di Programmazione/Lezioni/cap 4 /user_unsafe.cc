#include "risorsa_exc.hh"

void codice_utente(){
    Gestore_Risorsa r1; 

    usa_risorsa_exc(r1.get());

    Gestore_Risorsa r1; 
    usa_risorse_exc(r1.get(), r2.get());
    //restituisci implicito r2
    Gestore_Risorsa 3;
    usa_risorse_exc(r1.get(), r3.get());
    //restitiuisci implicito r3 e r1 

}