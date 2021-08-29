//Mostrare il processo di risoluzione dell’overloading per le seguenti chiamate di funzione. Per ogni chiamata, indicare l’insieme delle funzioni candidate, l’insieme delle funzioni utilizzabili e, se esiste, la migliore funzione utilizzabile.
#include <string>
class D;
class C {
 private:
 // ...
 public:
  C() {}
  C(const D&) {}
  // ...
};
class D {
 private:
 // ...
 public:
  D() {}
  D(const C&) {}
  // ...
};
void f(double d); // funzione #1
void f(int i, C c = C()); // funzione #2
void f(double d, C c = C()); // funzione #3

void g(C c, D d); // funzione #4
void g(D d, C c = C()); // funzione #5

void h(const char* s);// funzione #6
void h(const std::string& s); // funzione #7

int main() {
 C c;
 D d;
 f('a');  // chiamata #1
 f('a', c);  // chiamata #2
 f(3.2); // chiamata #3
 g(c, d);  // chiamata #4
 g(d, c);  // chiamata #5
 g(c);  // chiamata #6
 g(d);  // chiamata #7
 h("abra");  // chiamata #8
 h('a'); // chiamata #9
}

/*
-- chiamata 1 
cand: 1,2,3
util: 1,2,3
migliore: 2 (promozione, invece di conv std)

-- chiamata 2 
cand: 1,2,3
util: 2,3
migliore: 2

-- chiamata 3 
cand: 1,2,3
util: 1,2,3
migliore:  1,3 ambiguo (match perfetto)

-- chiamata 4 
cand: 4,5
util: 4,5
migliore: 4

-- chiamata 5 
cand: 4,5
util: 4,5
migliore: 5

-- chiamata 6 
cand: 4,5
util: 5
migliore: 5

-- chiamata 7 
cand: 4,5
util: 5
migliore: 5

-- chiamata 8 
cand: 6,7
util: 6,7
migliore: 6

-- chiamata 9 
cand: 6,7
util: 
migliore:



*/
