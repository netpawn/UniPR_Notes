//Scrivere l’implementazione dell’algoritmo della STL remove_copy_if, che ha come parametri una sequenza di input ed una sequenza di output, specificate mediante iteratori, ed un predicato unario.
//L’algoritmo copia nella sequenza di output, mantenendone l’ordine, gli elementi della sequenza di input che non soddisfano il predicato; l’algoritmo restituisce l’iteratore corrispondente alla fine della sequenza di output.
//Utilizzando l’algoritmo precedente, implementare l’analogo algoritmo remove_if, che invece di scrivere su di una sequenza di output modifica direttamente la sequenza di input. Motivare brevemente quali siano le categorie di iteratori utilizzabili in ognuno dei due algoritmi.
#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
template <typename in_Iter, typename out_Iter, typename UnaryPred>
out_Iter
remove_copy_if_1 (in_Iter first1, in_Iter last1, out_Iter first2, UnaryPred pred){
  for(;first1!=last1;++first1){
    if (!pred(*first1)) {
       *first2=*first1;
       ++first2;
  }}
  return first2;
}
bool pari (int x){
 if (x%2==0) return true;
 else return false;
}

template <typename Iter, typename UnaryPred>
Iter
remove_if_1 (Iter first, Iter last, UnaryPred pred){ //se pred restituisce false ->elimino
  auto i=first;
  for(;first!=last;++first){
    if (pred(*first)) {
       *i=*first;
       ++i;
  }}
  return i;
}

int main(){
 std::vector<int> c={1,2,3,4};
 std::ostream_iterator<int> out (std::cout);
 auto i=remove_copy_if_1(c.begin(),c.end(),out,pari);
 remove_if_1(c.begin(),c.end(),pari);
 std::copy(c.begin(),c.end(),out);
 return 0;
}



