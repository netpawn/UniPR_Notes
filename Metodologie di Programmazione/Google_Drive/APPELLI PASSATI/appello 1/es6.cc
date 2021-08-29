//Si fornisca un’implementazione per l’algoritmo generico
//template <typename Iter, typename T>
//void replace(Iter first, Iter last, const T& old_value, const T& new_value);
//che rimpiazza, nella sequenza individuata da first e last, ogni occorrenza di old_value con
//una copia di new_value. Elencare i requisiti imposti dall’implementazione sui sei parametri 
//della funzione.

#include <iostream>
#include <vector>
#include <iterator>

template <typename Iter, typename T>
void replace(Iter first, Iter last, const T& old_value, const T& new_value){
  for(;first!=last;++first){
    if(*first==old_value) *first=new_value;
  }
  return;
}

int main(){
std::vector<int> v={1,2,3,3,4,3};
replace(v.begin(),v.end(),3,9);
std::ostream_iterator<int> out (std::cout,"\n");
std::copy(v.begin(),v.end(), out);
   
return 0;

}

//sono concessi iteratori bidirezionali,forward,random access
//old value e new value devono essere dello stesso tipo e comunque compatibili con il tipo della sequenza
