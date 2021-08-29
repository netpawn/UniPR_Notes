//Mostrare il processo di risoluzione dell’overloading per le seguenti chiamate di funzione. Per ogni chiamata, indicare: l’insieme delle funzioni candidate; l’insieme delle funzioni utilizzabili; la migliore funzione utilizzabile (se esiste); il motivo di eventuali errori di compilazione.

#include <string>
namespace N {

 class C {
  private:
   std::string& first(); // funzione #1
  public:
   const std::string& first() const; // funzione #2
   std::string& last(); // funzione #3
   const std::string& last() const; // funzione #4
   C(const char*); // funzione #5
}; // class C 

 void print(const C&); // funzione #6
 std::string& f(int); // funzione #7

} // namespace N

class A {
 public:
  explicit A(std::string&); // funzione #8
}; //classe A

 void print(const A&); // funzione #9 
 void f(N::C& c) // funzione #10
 {
  const std::string& f1 = c.first(); //chiamata #1
  std::string& f2 = c.first(); //chiamata #2
  const std::string& l1 = c.last(); //chiamata #3
  std::string& l2 = c.last(); //chiamata #4
 }
 void f(const N::C& c) // funzione #11
 {
  const std::string& f1 = c.first(); //chiamata #5
  std::string& f2 = c.first(); //chiamata #6
  const std::string& l1 = c.last(); //chiamata #7
  std::string& l2 = c.last(); //chiamata #8
 }

int main() {
 N::C c("begin"); //chiamata #9 inizializzaz ogg c di classe C
 f(c); //chiamata #10
 f("middle"); //chiamata #11
 print("end"); //chiamata #12
}
/*
-- chiamata 9 --
cand: 5
util: 5
migliore: 5

-- chiamata 10 --
cand: 7,10,11
util: 10,11
migliore: 10

-- chiamata 1 --
cand: 1,2
util: 1,2
migliore: 1 ma non accessibile

-- chiamata 2 --
cand: 1,2
util: 1,2
migliore: 1 ma non accessibile

-- chiamata 3 --
cand: 3,4
util: 3,4
migliore: 3

-- chiamata 4 --
cand: 3,4
util: 3,4
migliore: 3

-- chiamata 11 --
cand: 10,11
util: 10,11
migliore: 10


-- chiamata 12 --
cand: 6
util: 6
migliore: 6








*/

