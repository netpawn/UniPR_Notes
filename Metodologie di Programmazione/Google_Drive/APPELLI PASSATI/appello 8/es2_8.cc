//Si forniscano il prototipo e l’implementazione della funzione generica count_if, che dati in ingresso una sequenza ed un predicato unario, restituisce il numero di elementi di quella sequenza per i quali quel predicato è soddisfatto.
//Utilizzando la funzione suddetta, scrivere un programma che legge dallo standard input una sequenza di std::string e scrive sullo standard output il numero di stringhe lette aventi una lunghezza maggiore di 10.

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

bool
maggiore_di_10 (std::string s){
 if(s.size()>10) return true;
 else return false;
}

template <typename Iter, typename UnaryPred>
unsigned
count_if1 (Iter first, Iter last, UnaryPred pred){
 unsigned ct=0;
 for(;first!=last;++first){
   if(pred(*first)) ++ct;
 }
 return ct;
}

int main(){
 std::vector<std::string> vi;
 std::istream_iterator<std::string> in (std::cin), i_end;
 std::copy(in,i_end,std::back_inserter(vi));
 unsigned n;
 n=count_if1(vi.begin(),vi.end(),maggiore_di_10);
 std::cout<<n<<std::endl;
   
}
//ctrl -D per interrompere immissione input
