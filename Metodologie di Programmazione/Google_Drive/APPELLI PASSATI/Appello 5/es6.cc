//La seguente gerarchia di classi è scorretta dal punto di vista della gestione delle risorse. Scrivere semplici esempi di codice che evidenzino due distinti comportamenti errati del programma, spiegando il tipo di problema ed indicando il punto in cui si viene a creare. Quindi applicare alle classi le modifiche minimali che consentano di evitare tali problemi.
/*
#include <iostream>
class Base {
 private:
  int* pi;
  // Assegnamento: privato e non implementato.
  Base& operator=(const Base&);
 public:
  Base() : pi(new int) {}
  Base(const Base& b) : pi(new int) { *pi = *(b.pi); }
  Base(int i){ pi=new int(i);}
  
  ~Base() { delete pi; }
  int foo() { return *pi; } 
};

class Derived : public Base {
 private:
  int* pj;
  // Assegnamento: privato e non implementato.
  Derived& operator=(const Derived&);
 public:
  Derived() : pj(new int) {}
  Derived(int i){ pj=new int(i);}
  ~Derived() { delete pj; }
  int foo() { return *pj; + Base::foo(); }
};
*/
//il costruttore di copia di Derived non è implementato nè eliminato
//di default copierà i puntatori->due puntatori che puntano a stessa risorsa
//doppia eliminazione

#include <iostream>
class Base {
 private:
  int* pi;
  // Assegnamento: privato e non implementato.
  Base& operator=(const Base&);
 public:
  Base() : pi(new int) {}
  Base(const Base& b) : pi(new int) { *pi = *(b.pi); }
  Base(int i){ pi=new int(i);}
  
  ~Base() { delete pi; }
  int foo() { return *pi; } 
  Base(Base&&)=delete;
};

class Derived : public Base {
 private:
  int* pj;
  // Assegnamento: privato e non implementato.
  Derived& operator=(const Derived&);
  Derived (const Derived&);
 public:
  Derived() : pj(new int) {}
  Derived(int i){ pj=new int(i);}
  ~Derived() { delete pj; }
  int foo() { return *pj; + Base::foo(); }
};

int main (){
Derived d (1);
Base* c=&d;
Derived f(d);
//int i=d.foo();
std::cout<<i<<std::endl;

return 0;

}
