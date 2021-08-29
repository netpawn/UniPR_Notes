/*

Esercizio 1

*/

/*

Chiamata A: (1,2) - (1) - (1)
Chiamata B: (10) - (10) - (10)
Chiamata C: (5,6) - (6) - (6) -> ADL
Chiamata D: (5,6) - (5) - (5)
Chiamata E: / - / - /
Chiamata F: (7,8) - (7,8) - (8)
Chiamata G: (7,8) - (7,8) - (7)
Chiamata H: (9) - (9) - (9) -> ADL
Chiamata I: (11,12) - (11) - (11)
Chiamata J: (3,4) - / - / -> ADL

*/



/*

Esercizio 2

*/

=== 1 ===
B::f(int)
B::g(int)
B::f(int)
C::g(int)
=== 2 ===
A::f(double)
B::f(int)
C::g(int)
=== 3 ===
B::f(int)
C::g(int)
=== 4 ===
Destructor C::~C()
Destructor B::~B()
Destructor A::~A()
Destructor B::~B()
Destructor A::~A()


/*

Esercizio 3

*/

/*

Possiamo notare come in questo codice il principio SOLID che viene violato è ISP.
Interface Segregation Principle dice infatti che bisogna cercare, per quanto possibile, di separare tutte le interfacce che possono essere usate separatamente.
Questo porta vantaggi come la possibilità di modificare parti di codice senza intaccare le altre già funzionanti e evita la propagazione di errori.
Un possibile modo per farlo in questo caso potrebbe essere il seguente.

*/

class Var : public Expr {
  void print(name()) const;

  double eval(const Var_Bindings& vb) const {
    return vb[name()];
  }
};

class Const : public Expr {
  void print(value()) const;

  double eval(const Var_Bindings& vb) const {
    return value();
  }
};

class Add : public Expr {
  void print(arg1, arg2) const {
    arg1.print();
    print(" + ");
    arg2.print();
  }

  double eval(const Var_Bindings& vb) const {
    return arg1().eval(vb) + arg2().eval(vb);
  }
};

class Sub : public Expr {
  void print(arg1, arg2) const {
    arg1.print();
    print(" - ");
    arg2.print();
  }

  double eval(const Var_Bindings& vb) const {
    return arg1().eval(vb) - arg2().eval(vb);
  }
};


class Expr {
public:
  Kind kind;
  // ...

  // Overriding
  virtual void print() const = 0;
  virtual double eval(cons Var_Bindings& vb) const = 0;
};

/*

Esercizio 4

*/

#include <string>
#include <vector>
#include <iostream>

typedef std::vector<std::string> vect;
typedef std::vector<std::string>::iterator iter;

void f(const vect& v) {
  iter i = std::find(v.begin(), v.end(), "inizio");
  iter i_end = std::find(v.begin(), v.end(), "fine");
  while (i != i_end) {
      std::cout << *i << std::endl;
    ++i;
  }


void g(vect& v) {
  iter i = v.begin(), i_end = v.end();

  // Inserisco un controllo (come nella funzione 'f') in caso il vettore fosse vuoto.
  // Gestiamo quindi il caso in cui i=i_end.
  v.insert(++i, "prima");
  v.insert(++i, "dopo");

  i=v.begin();
  while (i != v.end()) {
    std::cout << *i << std::endl;
    ++i;
  }
}

/*

Esercizio 5

*/

#include <iostream>
#include <list>
#include <iterator>

template<typename Iter1, typename Iter2, typename Out, typename Pred>
Out tranform
(Iter1 i1_first, Iter1 i1_last, Iter2 i2_first, Iter2 i2_last, Out i3_first, Pred p) {

  for( ; i1_first != i2_last; i1_first++, i2_first++, i3_first++) {
    *i3_first = p(*i1_first, *i2_first);
  }

  return i3_first;
}

double media(int arg1, int arg2) {
  double m = arg1 + arg2;
  m = m/2;

  return m;
}

int main() {
  std::list<int> list1 = {1, 5, 7, 9, 6};
  std::list<int> list2 = {3, 6, 2, 9, 5};

  // Iteratore di output in cui inserire i valori delle medie calcolate.
  // Verranno stampati su standard di output separati da una tabulazione.
  std::ostream_iterator<double> out (std::cout, "\t");

  transform(list1.begin(), list1.end(), list2.begin(), list2.end(), out.begin(), media);

  return 0;
}


/*

Esercizio 6

*/

/*

All'interno della funzione 'foo' quando viene utilizzata la funzione 'job' notiamo che 'pc' è stato già allocato, questo vuol dire che se l'allocazione di 'C' (che viene poi passato a 'pc2') non va a buon fine 'pc' non verrà eliminato.
Per questo è necessario utilizzare un try-catch nella parte di codice sensibile oppure implementare l'idioma RAII.

*/

// Gestione con try-catch

struct C { ~C() {} /* ... */ //};
struct D : public C { /* ... */ };
void job(const C* pc1, const C* pc2){}

void foo() {
  C* pc = new D();

  try{
    C* pk = new C();
    try {
      job(pc, pk);
    }
    catch(...) {
      delete pk;
      throw;
    }
    delete pk;
    delete pc;
  }
  catch(...) {
    delete pc;
    throw;
  }
}

// Gestione RAII e smart pointer

struct C { ~C() {} /* ... */ //};
struct D : public C { /* ... */ };
void job(const C* pc1, const C* pc2){}

void foo() {
  std::unique_ptr<D> pc (new D());
  std::unique_ptr<C> pk (new C());

  job(pc.get(), pk.get();
}
