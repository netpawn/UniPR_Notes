//Mostrare il processo di risoluzione dell’overloading per le seguenti chiamate di funzione. Per ogni chiamata, indicare: l’insieme delle funzioni candidate; l’insieme delle funzioni utilizzabili; la migliore funzione utilizzabile (se esiste); il motivo di eventuali errori di compilazione.

#include <iostream>
class Base {
 public:
  void f(int, double); //funzione #1
  void f(double, int) const; //funzione #2
  void g(double); //funzione #3
  void print(std::ostream&) const; //funzione #4
};
class Derived : public Base {
 public:
  using Base::f;
  void f(double, double); //funzione #5
  void g(double) const; //funzione #6
 private:
  void print(std::ostream&); //funzione #7
};

int main() {
 Base b;
 Derived d;
 Base* pb = &d;
 const Derived* pd = &d;

 b.print(std::cout); //chiamata (a)
 d.print(std::cerr); //chiamata (b)
 pb->print(std::cerr); //chiamata (c)
 pd->print(std::cout); //chiamata (d)

 b.f('a', 0.7); //chiamata (e)
 d.f(12.5, 1.4); //chiamata (f)
 pb->f(2, 0); //chiamata (g)
 pd->f(7.2, 7); //chiamata (h)
 pd->f(7, 7.2); //chiamata (i)

 const Base* pb2 = static_cast<const Base*>(pd);
 pb2->g(0.0); // chiamata (j)
 pd->g(0.0);// chiamata (k)
}

/*
-- chiamata a 
cand: 4
util: 4
migliore: 4

-- chiamata b 
cand: 7
util: 7
migliore: 7 ma non accessibile ->errore

-- chiamata c 
cand: 4
util: 4
migliore: 4

-- chiamata d 
cand: 7
util: non è const
migliore:   

-- chiamata e --
cand: 1,2
util: 1,2
migliore: 1

-- chiamata f --
cand: 1,2,5
util: 1,2,5
migliore: 5

-- chiamata g 
cand: 1,2
util: 1,2
migliore: ambiguo

-- chiamata h 
cand: 1,2,5
util: 2
migliore: 2

-- chiamata i 
cand: 1,2,5
util: 2
migliore: 2

-- chiamata j 
cand: 3
util: (ogg è const)
migliore: 

-- chiamata k 
cand: 6
util: 6
migliore: 6
*/
