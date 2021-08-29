#include "risorsa_raii.hh"

void codice_utente() {
  Gestore_Risorsa r1;
  usa_risorsa_exc(r1.get());
  {
    Gestore_Risorsa r2;
    usa_risorse_exc(r1.get(), r2.get());
  }
  Gestore_Risorsa r3;
  usa_risorse_exc(r1.get(), r3.get());
}


