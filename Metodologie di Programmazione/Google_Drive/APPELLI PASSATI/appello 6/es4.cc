//Scrivere l’implementazione dell’algoritmo generico della STL max_element, che prende come input una sequenza ed un criterio di ordinamento (un predicato binario) e restituisce l’iteratore all’elemento massimo contenuto nella sequenza (comportandosi in modo standard nel caso di sequenza vuota). Elencare in modo esaustivo i requisiti imposti dall’implementazione sui parametri di tipo e sugli argomenti della funzione. In particolare, individuare le categorie di iteratori che non possono essere utilizzate per istanziare il template, motivando la risposta.

template <typename Fwd_Iter, typename BinPred >
Fwd_Iter
max_element(Fwd_Iter first, Fwd_Iter last, BinPred pred){ //pred(a,b) se true a<b
  if(first==last) return last;
  auto max=first;
  for(;first!=last; ++first){
    if(pred(*max,*first) max=first;
  }
  return max;
}

