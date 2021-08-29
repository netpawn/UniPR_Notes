#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

/*
template <typename Iter, typename Pred>
int count_if(Iter i, Iter i_end, Pred p){
    int n;
    for( ; i!=i_end; ++i){
        if(p(*i))
            n++;
        return n;
    }
} */

//2006 02 06
template <typename Iter1, typename Iter2, typename Pred>
int find_first_of(Iter1 first1, Iter1 last1, Iter2 first2, Iter2 last2, Pred p){
    for( ; first1!=last1; ++first1){
        for( Iter2 it = first2; first2!=it; ++it){ //creo it e ci copio iter2
            if(pred(*first1, first2)){
                return first1;
            }
        }

    }
};


//2005 02 01

template <typename Iter, typename T>
void replace(Iter first, Iter last, const T& old_value, const T& new_value){
for ( ; first!=last; ++first){
	if(*first==old_value)
		*first = new_value;
}

}
/* Iter deve fornire il concetto di iteratore, deve perciò permettere di
scorrere una sequenza, dereferenziarsi, confrontarsi ed essere
copiabile.
Il tipo di dato T deve permettere il confronto. */



#include <iostream>
#include <iterator>
#include <vector>

template <typename Iter>
tmax_elemets(Iter start, Iter end){
    iter max= inizio;
    if(start == fine)throw "nope";
    else{
        for(;start!=end; ++start){
            if(*max < *inizio) max = inizio;
        }   return max;
    }
}; 
