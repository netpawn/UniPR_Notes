//Il codice seguente non ha un comportamento corretto in presenza di eccezioni. Individuare il problema, indicando la sequenza di operazioni che porta alla sua occorrenza, e correggerlo applicando l’idioma “l’acquisizione di risorse è una inizializzazione”.
#include <memory>

class One {
 int i_one;
};

class Two {
 int i_one;
 int i_two;
};
class Three{
 int i_one;
 int i_two;
 int i_three;
};
/*
class OneTwoThree {
 private:
  One one;
  Two* p_two;
  Three* p_three;
  // Dichiarati privati e non implementati.
  OneTwoThree(const OneTwoThree&);
  OneTwoThree& operator=(const OneTwoThree&);
 public:
  OneTwoThree(const One& o, const Two& t) {
   one = o;
   p_two = new Two(t); //se errore ok
   p_three = new Three(); //se errore p_two deve essere eliminato
  }
  
  ~OneTwoThree() {
   delete p_two;
   delete p_three;
  }
  // ...
};

*/

//classe corretta
class OneTwoThree {
 private:
  One one;
  std::unique_ptr<Two> p_two;
  std::unique_ptr<Three> p_three;
  // Dichiarati privati e non implementati.
  OneTwoThree(const OneTwoThree&);
  OneTwoThree& operator=(const OneTwoThree&);
 public:
  OneTwoThree(const One& o, const Two& t) {
   one = o;
   p_two = std::make_unique<Two>(t); 
   
   p_three = std::make_unique<Three>(); 
  }
  
 
  ~OneTwoThree() =default;
  // ...
};

int main (){
One o;
Two t;
OneTwoThree c( o, t);
std::unique_ptr<int> prova (new int);
return 0;
}


 
