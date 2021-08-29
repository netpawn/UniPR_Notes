//Il codice seguente aggiunge al secondo argomento una copia degli elementi di tutte le liste contenute nel primo argomento (una lista di liste), realizzando quindi una sorta di concatenazione multipla.
#include <list>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;
/*
template <typename T>
void f(const list<list<T> >& ll, list<T>& l) {
 for (typename list<list<T> >::const_iterator ll_i = ll.begin(),
       ll_end = ll.end(); ll_i != ll_end; ++ll_i)
      for (typename list<T>::const_iterator i = ll_i->begin(),
           i_end = ll_i->end(); i != i_end; ++i)
         l.push_back(*i);
}*/
//Generalizzare il codice affinché, mantenendo la funzionalità descritta, possa lavorare non solo con il tipo lista, ma con combinazioni qualunque dei contenitori sequenziali della STL.
//Generalizzare ulteriormente il codice affinché accetti come argomenti, invece di contenitori sequenziali della STL, degli iteratori. Fornire un (semplice) esempio di applicazione della versione con iteratori che non possa essere codificato utilizzando la versione con contenitori.

template <typename Container1, typename Container2>

void f(const Container1& ll,  Container2& l) {
 auto l_i=l.begin();
 for (auto ll_i = ll.begin(), ll_end = ll.end(); ll_i != ll_end; ++ll_i)
  copy(ll_i->begin(),ll_i->end(),std::back_inserter(l));
  
}

int main (){
 std::list<list<int> > c= {{1,2,3},{3,4,5}};
std::list<int> h={5,6,7};
 f(c,h);
 return 0;
}

