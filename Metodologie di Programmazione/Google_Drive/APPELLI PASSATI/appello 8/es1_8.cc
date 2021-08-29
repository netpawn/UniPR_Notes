//Mostrare il processo di risoluzione dell’overloading per le seguenti chiamate di funzione. Per ogni chiamata, indicare: l’insieme delle funzioni candidate; l’insieme delle funzioni utilizzabili; la migliore funzione utilizzabile (se esiste); il motivo di eventuali errori di compilazione.
#include <iostream>
class Base {
 public:
  void f(int, double); // funzione #1
  void f(double, int) const; // funzione #2
  void g(double); // funzione #3
  void print(std::ostream&) const; // funzione #4
};

class Derived : public Base {
 public:
  using Base::f;
  void f(double, double); // funzione #5
  void g(double) const; // funzione #6
 private:
  void print(std::ostream&); // funzione #7
};

int main() {
 Base b;
 Derived d;
 Base* pb = &d;
 const Derived* pd = &d;
 pb->print(std::cerr); // chiamata (a)
 pd->print(std::cout); // chiamata (b)
 
 b.f('a', 0.7); // chiamata (c)
 d.f(12.5, 1.4); // chiamata (d)
 pb->f(2, 0); // chiamata (e)
 pd->f(7.2, 7); // chiamata (f)

 const Base* pb2 = static_cast<const Base*>(pd);
 pb2->g(0.0); // chiamata (g)
 pd->g(0.0); // chiamata (h)
}

/*
-- chiamata a --
cand: 4 
util: 4
migliore: 4

-- chiamata b --
cand: 7
util: 
migliore: 

-- chiamata c --
cand: 1,2
util: 1,2,
migliore: 1

-- chiamata d --
cand: 1,2,5
util: 1,2,5
migliore: 5

-- chiamata e --
cand: 1,2
util: 1,2
migliore: ambiguo

-- chiamata f --
cand: 1,2,5  
util: 2
migliore: 2

-- chiamata g --
cand: 3
util: 
migliore: 

-- chiamata h --
cand: 6
util: 6
migliore: 6 
 
 
 







*/
