//Il seguente codice non ha un comportamento corretto in presenza di eccezioni (nota: si assume che le funzioni lock e unlock facciano la cosa giusta e che la funzione unlock non possa lanciare eccezioni).
//Individuare il problema, indicando la sequenza di operazioni che porta alla sua occorrenza, e correggerlo applicando un numero minimo di modifiche al codice. Fornire quindi una soluzione alternativa applicando l’idioma “l’acquisizione di risorse è una inizializzazione”.
void f() {
 lock("lock1"); //se lancia eccez no problem, non abbiamo altre risorse
 try {
  lock("lock2");
  try {
   do_the_job();
   unlock("lock2");
   unlock("lock1");
  } catch (...) {
   unlock("lock2");
  }
 } catch (...) {
  unlock("lock1");
}
}

//problema: il catch dedicato alla risorsa 2 non rilancia l'eccezione -> se do_the_job lancia eccez viene rilasciata solo la risorsa 2. anche il catch della risorsa 1 deve fare throw

void f() {
 lock("lock1");
 try {
  lock("lock2");
  try {
   do_the_job();
   unlock("lock2");
   unlock("lock1");
  } catch (...) {
   unlock("lock2");
   throw;
  }
 } catch (...) {
  unlock("lock1");
  throw;
}
}

//usiamo il gestore
struct Risorsa;
class GestoreRisorsa{
 private:
  Risorsa* ris;
 public:
  GestoreRisorsa();
  GestoreRisorsa(const GestoreRisorsa&)=delete;
  ~GestoreRisorsa();
  GestoreRisorsa& operator=(const GestoreRisorsa&)=delete;
  GestoreRisorsa& operator=(GestoreRisorsa&&);
  GestoreRisorsa(GestoreRisorsa&&);
}


void f() {
 GestoreRisorsa gr1;
 gr1.ris=Risorsa1;
 GestoreRisorsa gr2;
 gr2.ris=Risorsa2;
 do_the_job();
  
}

// con smart pointer
#include <memory>
#include <string>
void f(){
std::unique_ptr<std::string> r1=std::make_unique<std::string> ("lock1");
std::unique_ptr<std::string> r2=std::make_unique<std::string> ("lock2");
do_the_job();
}

 
  


