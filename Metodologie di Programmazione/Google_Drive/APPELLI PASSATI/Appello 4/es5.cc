//Scrivere l’implementazione dell’algoritmo della STL find_first_of. L’algoritmo prende in input due sequenze [first1, last1) e [first2, last2), specificate mediante iteratori, ed un predicato binario comp. Utilizzando il predicato come operatore di confronto, l’algoritmo cerca nella prima sequenza il primo elemento “uguale” ad un elemento qualunque della seconda sequenza. Se lo trova, restituisce l’iteratore corrispondente; altrimenti, restituisce last1. Si noti che le due sequenze possono avere tipi diversi. Indicare, motivando la risposta, la più ampia categoria di iteratori utilizzabile per ognuna delle due sequenze di input.

template <typename Iter1, typename Iter2, typename BinPred>
Iter1
find_first_of(Iter1 first1, Iter1 last1, Iter2 first2, Iter2 last2, BinPred comp){
  for(;first1!=last1;++first1){
     for(;first2!=last2;++first2){
       if(comp(*first1,*first2)) return first1;
     }
  }
  return last1;
}

//Iter2 deve essere almeno forward iter. può anche essere bidirezionale,random access
//Iter1 può essere di input 
