#ifndef GUARDIA_risorsa_exc_hh
#define GUARDIA_risorsa_exc_hh 1

#include "risorsa_no_exc.hh"

struct exception_acq_risorsa{};
struct exception_uso_risorsa{};
class Gestore_Risorsa{
    const Risorsa* get() const {return res_ptr;}
    Risorsa* get(){return res_ptr;}




//CODICE MANCANTE IN USER UNSACE CC
// 24 MIN GESTIONE RISORSE IDIOMA RAII 




};

//lancia una eccezzione se non riesce ad acquisire
inline Risorsa* 
acquisisci_risorsa_exc(){
    Risorsa* r = acquisisci_risorsa();
    if(r==nullptr){
        throw exception_acq_risorsa();
    }return r; 
}

//lancia una eccezione se si è verificato un problema 
inline void 
usa_risorsa_exc(Risorsa* r){
    if(usa_risorsa(r))
    throw exception_uso_risorsa(); 
}

//lancia una eccezione se si è verificato un problema 
inline void
usa_risorse_exc(Risorsa* r1, Risorsa* r2){
    if(usa_risorse(r1, r2))
    throw exception_uso_risorsa();
}

#endif //GUARDIA_risorsa_exc_hh



/*

IDIOMA RAII _ RRID 

RAI -> resource acquisition is initialization 
l'acquisizone delle risorse deve avvenire nel costruttore 

RRID resource release is destruction 

*/