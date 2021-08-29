/*
Si forniscano il prototipo e l’implementazione della funzione generica count_if,
che dati in ingresso una sequenza ed un predicato unario, restituisce il numero di
 elementi di quella sequenza per i quali quel predicato `e soddisfatto.
Utilizzando la funzione suddetta, scrivere un programma che legge dallo standard
input una sequen- za di std::string e scrive sullo standard output il numero di
stringhe lette aventi una lunghezza maggiore di 10.
*/
#include <iostream>
#include <string>
#include <iterator> //mi serve per usare gli iteratori
#include <vector> //ho bisogno di un contenitore
using namespace std;

template <typename Iter, typename Pred>
int count_if(Iter i, Iter i_end, Pred p){
    int n=0;
    for ( i=0 ; i != i_end; ++i )
    if(p(*i))
        n++;
    return n;
}

int main(){

    return 0;
}
