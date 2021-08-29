#ifndef GUARDIA_risorsa_no_exc_hh
#define GUARDIA_risorsa_no_exc_hh 1

//tipo dichiarato ma non definito per puntatori opachi 
struct Risorsa; 

//restituisce un puntatore nulla se l'acquisizione fallisce
Risorsa* acquisisci_risorsa(); 

//restituisce true se si è verificato un problema 
bool usa_risorsa(Risorsa* r); 

//restituisce true se si è verificato un problema 
bool usa_risorse(Risorsa* r1, Risorsa* r2); 

void restituisci_risorsa(Risorsa* r);

int get();

#endif // GUARDIA_risorsa_no_exc_hh
