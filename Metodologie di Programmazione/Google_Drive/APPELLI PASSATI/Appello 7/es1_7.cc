//Mostrare il processo di risoluzione dell’overloading per le seguenti chiamate di funzione. Per ogni chiamata, indicare l’insieme delle funzioni candidate, l’insieme delle funzioni utilizzabili e, se esiste, la migliore funzione utilizzabile.
#include <iostream>
namespace N {
 struct C {
  C(int); // funzione #1
  C(const C&); // funzione #2

  void m(); // funzione #3
  void m(int); // funzione #4
 };
 void f(double d); // funzione #5
 void f(const C& c); // funzione #6
 void g(int i, double d); // funzione #7
 void g(int i, int j); // funzione #8
 void h(C* pc); // funzione #9

} // namespace N

void f(char);  // funzione 10

int h(const char* s = 0); // funzione 11
int h(const N::C* pc); // funzione 12

int main() {
 N::C c(5); // chiamata A
 
 f(5); // chiamata B
 f(c); // chiamata C
 N::f('a'); // chiamata D
 
 g(5, 3.7); // chiamata E
 N::g(2.3, 5); // chiamata F
 N::g(5, 2.3); // chiamata G

 h(&c); // chiamata H
 h(); // chiamata I

 m(&c); // chiamata J
}

/*
-- chiamata a 
cand: 1,2
util: 1 
migliore: 1

-- chiamata b 
cand: 10
util: 10
migliore: 10

-- chiamata c 
cand: 5,6
util: 6
migliore: 6

-- chiamata d 
cand: 5,6
util: 5
migliore: 5

-- chiamata e --
cand: 
util: 
migliore: 

-- chiamata f --
cand: 7,8
util: 7,8
migliore: 8

-- chiamata g --
cand: 7,8
util: 7,8
migliore: 7

-- chiamata h --
cand: 9
util: 9
migliore: 9

-- chiamata i --
cand: 11,12
util: 11,12
migliore: 11

-- chiamata j --
cand: 3,4
util: 
migliore: 


*/
