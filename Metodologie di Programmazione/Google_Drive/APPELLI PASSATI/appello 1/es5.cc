//Utilizzando gli algoritmi generici forniti dalla libreria standard, implementare la funzione
//void f(const std::vector<std::string>& vs, const char c);
//che stampa, in ordine lessicografico, tutte le stringhe in vs che iniziano con il carattere c. 
//Fornire una versione alternativa nella quale si inverte l’ordine di stampa.

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
//using namespace std;

void f(const std::vector<std::string>& vs, const char c){
  auto v1=vs;
  std::sort(v1.begin(),v1.end());
  std::ostream_iterator<std::string> out (std::cout,"\n");
  std::copy_if(v1.begin(),v1.end(), out, [c] (std::string s){ //passi ogg (*iter)
   return *(s.begin())==c;
}
);
  
}

void f1(const std::vector<std::string>& vs, const char c){
  auto v1=vs;
  std::sort(v1.begin(),v1.end());
  std::ostream_iterator<std::string> out (std::cout,"\n");
  std::copy_if(v1.rbegin(),v1.rend(), out, [c] (std::string s){
   return *(s.begin())==c;
}
);
  
}


int main(){
std::vector<std::string> vs={"ciao", "come","stai", "acci"};
f(vs,'c');
f1(vs,'c');
return 0;
}


