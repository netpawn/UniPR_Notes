#ifndef GUARDIA_risorsa_exc_hh
#define GUARDIA_risorsa_exc_hh 1

#include "risorsa_no_exc.hh"

struct exception_acq_risorsa {};
struct exception_uso_risorsa {};

// Lancia una eccezione se non riesce ad acquisire la risorsa.
inline Risorsa*
acquisisci_risorsa_exc() {
  Risorsa* r = acquisisci_risorsa();
  if (r == nullptr)
    throw exception_acq_risorsa();
  return r;
}

// Lancia una eccezione se si è verificato un problema.
inline void
usa_risorsa_exc(Risorsa* r) {
  if (usa_risorsa(r))
    throw exception_uso_risorsa();
}

// Lancia una eccezione se si è verificato un problema.
inline void
usa_risorse_exc(Risorsa* r1, Risorsa* r2) {
  if (usa_risorse(r1, r2))
    throw exception_uso_risorsa();
}

#endif // GUARDIA_risorsa_exc_hh
