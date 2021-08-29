//Si forniscano il prototipo e l’implementazione della funzione generica transform i cui parametri specificano: (a) due sequenze di ingresso (non necessariamente dello stesso tipo), di cui si assume che la seconda sia lunga almeno quanto la prima; (b) una sequenza di uscita (potenzialmente di un tipo ancora diverso); (c) una funzione binaria applicabile a coppie di elementi in ingresso (il primo preso dalla prima sequenza, il secondo dalla seconda) e che restituisce un elemento assegnabile alla sequenza di uscita.
//La funzione transform applica la funzione binaria agli elementi in posizione corrispondente nelle due sequenze di ingresso, assegnando il risultato ad elementi consecutivi della sequenza di uscita. Utilizzando la funzione suddetta, scrivere una funzione che, date due liste di interi [i 1 , . . . , i n ] e [j 1 , . . . , j n ] scrive sullo standard output la sequenza delle medie aritmetiche (di tipo double) [(i 1 + j 1 )/2, . . . , (i n + j n )/2].

#include <iostream>
#include <iterator>
#include <list>
template <typename in_iter1, typename in_iter2, typename out_iter, typename Fun>
out_iter
transform( in_iter1 first1, in_iter1 last1, in_iter2 first2, out_iter first3, Fun fun) {
 for(;first1!=last1;++first1,++first2){
   
  *first3=fun(*first1,*first2);
   ++first3;
}
return first3;
}


double
fun(int l1, int l2){
 double media=l1+l2;
 media=media/2;
 return media;
}

void
funzione_base(std::list<int> l1, std::list<int> l2){
  std::ostream_iterator<double> out (std::cout,"\n");
  transform(l1.begin(),l1.end(),l2.begin(), out,fun);
}

int main(){
 std::list<int> l1= {5,6,7,8};
 std::list<int> l2={8,9,10,11};
 funzione_base(l1,l2);
 return 0;
}


