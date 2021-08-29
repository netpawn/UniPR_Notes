//Individuare i problemi presenti nel codice seguente e mostrare modifiche minimali per prevenirli:
#include <string>
#include <vector>
#include <iostream>

#include <algorithm>
typedef std::vector<std::string> vect;
typedef std::vector<std::string>::iterator iter;
/*
void f(const vect& v) {
 iter i = std::find(v.begin(), v.end(), "inizio");
 iter i_end = std::find(v.begin(), v.end(), "fine");
 while (i != i_end) {
 std::cout << *i << std::endl;
 ++i;
 }
}
*/
//problematiche che possono accadere:
//può succedere che non trovi nessuna stringa -> i=i_end=v.end() -> non stampa nulla
//i_end è precedente a i -> sono diversi e i viene incrementato all'infinito leggendo memoria casuale
//la find restituisce iteratore costante
/*
void g(vect& v) {
 iter i = v.begin(), i_end = v.end();
 v.insert(++i, "prima");
 v.insert(++i, "dopo")

}
*/
//se vect non ha elementi incrementando il puntatore scriviamo su memoria non di vector

void f(const vect& v) {
 auto i = std::find(v.begin(), v.end(), "inizio");
 auto i_end = std::find(v.begin(), v.end(), "fine");
 if(i>i_end) {auto temp=i; i=i_end; i_end=temp;}
 while (i != i_end) {
 std::cout << *i << std::endl;
 ++i;
 }
}

void g(vect& v) {
 iter i = v.begin(), i_end = v.end();
 if(i==i_end||i+1==i_end) return;
 i=v.insert(++i, "prima"); //inserisco nella posizione i
 i=v.insert(++i, "dopo");
auto g=v.begin();
while (g != v.end()) {
 std::cout << *g << std::endl;
 ++g;
 }
}


int main(){
 vect c={"fine","inizio"};
 vect s={"ciao","come"};
 f(c);
 g(s);
 return 0;
}
