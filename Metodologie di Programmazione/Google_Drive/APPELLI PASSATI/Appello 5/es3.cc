//Un’applicazione software si interfaccia ad un’apparecchiatura di comunicazione multi-funzione (fax e modem) mediante il corrispondente driver proprietario, utilizzando un file header come il seguente:

// File FaxModem.hh
class FaxModem_AllStars {
 private:
 // ...
 public:
  void fax_function_1();
  void fax_function_2(const char*);
  void fax_function_3(int);
  // ...
  void modem_function_1(const char*);
  void modem_function_2();
  void modem_function_3(unsigned int);
  // ...
};

//Il codice utente, nel quale le due funzionalità dell’apparecchiatura sono sempre utilizzate in contesti distinti, è il seguente:

// File User.cc
#include "FaxModem.hh"
void user_function_1(FaxModem_AllStars& f) {
 f.fax_function_1();
 // ...
 f.fax_function_3(12);
 // ...
}

void user_function_2(FaxModem_AllStars& m, const char* command) {
 m.modem_function_1(command);
 // ...
 m.modem_function_3(1024);
 // ...
}

void user_function_3(FaxModem_AllStars& f, FaxModem_AllStars& m) {
 f.fax_function_2("+390521906950");
 // ...
 m.modem_function_2();
 // ...
}

//L’utente vuole eliminare la dipendenza del proprio codice dal produttore AllStars, in quanto sul mercato esistono altri produttori di apparecchiature multifunzione analoghe, nonché produttori di apparecchiature che supportano una sola delle due funzionalità.
//Mostrare le modifiche da apportare in tal senso al codice utente, comprese eventuali nuove interfacce. In particolare, mostrare come il driver proprietario di AllStars (non modificabile dall’utente) possa essere interfacciato con il nuovo codice utente.

//Fax.hh
class Fax{
 private:
 //...
 public:
 virtual void fax_function_1()=0;
 virtual void fax_function_2(const char*)=0;
 virtual void fax_function_3(int)=0;
 virtual ~Fax(){};
}

//Modem.hh
class Modem{
 private:
 //...
 public:
 virtual void modem_function_1(const char*)=0;
 virtual void modem_function_2()=0;
 virtual void modem_function_3(unsigned int)=0;
 virtual ~Modem(){};
}

//Adapter.hh
#include "Fax.hh"
#include "Modem.hh"
#include "FaxModem.hh"

class AdapterAllStars : public Fax, public Modem{
 private:
  FaxModem_AllStars as;
 public:
  void fax_function_1() override{
   as.fax_function_1();
  }
  void fax_function_2(const char* x) override{
   as.fax_function_2(x);
  }
  void fax_function_3(int x) override{
   as.fax_function_3(x);
  }
  void modem_function_1(const char* x) override{
   as.modem_function_1(x);
 
  void modem_function_2() override{
   as.modem_function_2();
  }
  void modem_function_3(unsigned int x) override{
   as.modem_function_3(x);
  }
  
// File User.cc
#include "Modem.hh"
#include "Fax.hh"
void user_function_1(Fax& f) {
 f.fax_function_1();
 // ...
 f.fax_function_3(12);
 // ...
}

void user_function_2(Modem& m, const char* command) {
 m.modem_function_1(command);
 // ...
 m.modem_function_3(1024);
 // ...
}

void user_function_3(Fax& f, Modem& m) {
 f.fax_function_2("+390521906950");
 // ...
 m.modem_function_2();
 // ...
}
  
  
  
