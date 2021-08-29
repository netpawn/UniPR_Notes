#include "risorsa_no_exc.hh"

bool codice_utente() {
  Risorsa* r1 = acquisisci_risorsa();
  if (r1 == nullptr) {
    // errore durante acquisizione di r1: non devo rilasciare nulla
    return true;
  }

  // acquisita r1: devo ricordarmi di rilasciarla

  if (usa_risorsa(r1)) {
    // errore durante l'uso: rilascio r1
    restituisci_risorsa(r1);
    return true;
  }

  Risorsa* r2 = acquisisci_risorsa();
  if (r2 == nullptr) {
    // errore durante acquisizione di r2: rilascio di r1
    restituisci_risorsa(r1);
    return true;
  }

  // acquisita r2: devo ricordarmi di rilasciare r2 e r1

  if (usa_risorse(r1, r2)) {
    // errore durante l'uso: rilascio r2 e r1
    restituisci_risorsa(r2);
    restituisci_risorsa(r1);
    return true;
  }

  // fine uso di r2: la rilascio
  restituisci_risorsa(r2);
  // ho ancora r1: devo ricordarmi di rilasciarla

  Risorsa* r3 = acquisisci_risorsa();
  if (r3 == nullptr) {
    // errore durante acquisizione di r3: rilascio di r1
    restituisci_risorsa(r1);
    return true;
  }

  // acquisita r3: devo ricordarmi di rilasciare r3 e r1

  if (usa_risorse(r1, r3)) {
    // errore durante l'uso: rilascio r3 e r1
    restituisci_risorsa(r3);
    restituisci_risorsa(r1);
    return true;
  }

  // fine uso di r3 e r1: le rilascio
  restituisci_risorsa(r3);
  restituisci_risorsa(r1);

  // Tutto ok: lo segnalo ritornando false
  return false;
}
