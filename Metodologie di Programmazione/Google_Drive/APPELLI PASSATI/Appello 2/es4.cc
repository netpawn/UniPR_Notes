//Fornire il prototipo e l’implementazione della funzione templatica average, che prende come unico argomento un (non meglio identificato) contenitore sequenziale della libreria standard e restituisce come risultato la media aritmetica degli elementi contenuti. Elencare i requisiti imposti da tale funzione sul tipo degli elementi del contenitore.
//Riscrivere la funzione average facendo in modo che prenda come argomenti due iteratori che identificano la sequenza in ingresso. Per quale motivo questa seconda versione è più generale della precedente?
#include <iostream>
#include <vector>
#include <list>


template < class Container> 
double
average ( const Container& v){
  auto first=v.begin();
  auto last=v.end();
  size_t nelem=0;
  double ave=0;
  for(;first!=last;++first){
    ave=ave+*first;
    ++nelem;
  }
  ave/=nelem;
  return ave;
}
//gli elementi devono essere dei numeri

template <typename Iter>
double
average ( Iter first, Iter last){
  size_t nelem=0;
  double ave=0;
  for(;first!=last;++first){
    ave=ave+*first;
    ++nelem;
  }
  ave/=nelem;
  return ave;
}
//più generale perchè possiamo decidere in quale sottoseq calcolare la media

int main (){
 std::list<int> v1= {1,4,5,7};
 std::vector<int> v2= {1,2,3,4};
 
 double ave1=average (v1.begin(),v1.end());
 double ave2=average (v2.begin(),v2.end());
 ave1=average(v1);
 ave2=average(v2);
 std::cout<<ave1<<std::endl;
 std::cout<<ave2<<std::endl;
 return 0;
}



