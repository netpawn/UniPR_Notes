#include "risorsa_exc.hh"

void codice_utente() {
  Risorsa* r1 = acquisisci_risorsa_exc();
  try { // blocco try che protegge la risorsa r1
    usa_risorsa_exc(r1);

    Risorsa* r2 = acquisisci_risorsa_exc();
    try { // blocco try che protegge la risorsa r2
      usa_risorse_exc(r1, r2);
      restituisci_risorsa(r2);
    } // fine try che protegge r2
    catch (...) {
      restituisci_risorsa(r2);
      throw;
    }

    Risorsa* r3 = acquisisci_risorsa_exc();
    try { // blocco try che protegge la risorsa r3
      usa_risorse_exc(r1, r3);
      restituisci_risorsa(r3);
    } // fine try che protegge r3
    catch (...) {
      restituisci_risorsa(r3);
      throw;
    }
    restituisci_risorsa(r1);

  } // fine try che protegge r1
  catch (...) {
    restituisci_risorsa(r1);
    throw;
  }

}

/*
  Osservazioni:

  1) si crea un blocco try/catch per ogni singola risorsa acquisita

  2) il blocco si apre subito *dopo* l'acquisizione della risorsa
     (se l'acquisizione fallisce, non c'è nulla da rilasciare)

  3) lo responsabilità del blocco try/catch è di proteggere *quella*
     singola risorsa (ignorando le altre)

  4) al termine del blocco try (prima del catch) va effettuata la
     "normale" restituzione della risorsa (caso NON eccezionale)

  5) la clausola catch usa "..." per catturare qualunque eccezione:
     non ci interessa sapere che errore si è verificato (non è nostro
     compito), dobbiamo solo rilasciare la risorsa protetta

  6) nella clausola catch, dobbiamo fare due operazioni:
      - rilasciare la risorsa protetta
      - rilanciare l'eccezione catturata (senza modificarla)
        usando l'istruzione "throw;"

  Il rilancio dell'eccezione catturata (seconda parte del punto 6)
  garantisce la "neutralità rispetto alle eccezioni": i blocchi catch
  catturano le eccezioni solo temporaneamente, lasciandole poi
  proseguire. In questo modo anche gli altri blocchi catch potranno
  fare i loro rilasci di risorse e l'utente otterrà comunque l'eccezione,
  con le informazioni annesse, potendo quindi decidere come "gestirla".

*/
