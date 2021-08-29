/*
  Codice utente che vorrebbe lavorare su alcune risorse
  garantendo la corretta interazione con le risorse
  (acquisizione, uso e rilascio) anche in presenza di errori.
  Intuitivamente, si vorrebbe eseguire questa sequenza di operazioni:

    acquisisci risorsa r1
    usa risorsa r1

    acquisisci risorsa r2
    usa risorse r1 e r2
    restituisci risorsa r2

    acquisisci risorsa r3
    usa risorse r1 e r3
    restituisci risorsa r3
    restituisci risorsa r1

*/

/* Una codifica che NON è corretta in presenza di errori */

#include "risorsa_no_exc.hh"

void codice_utente() {
  Risorsa* r1 = acquisisci_risorsa();
  usa_risorsa(r1);
  Risorsa* r2 = acquisisci_risorsa();
  usa_risorse(r1, r2);
  restituisci_risorsa(r2);
  Risorsa* r3 = acquisisci_risorsa();
  usa_risorse(r1, r3);
  restituisci_risorsa(r3);
  restituisci_risorsa(r1);
}

















