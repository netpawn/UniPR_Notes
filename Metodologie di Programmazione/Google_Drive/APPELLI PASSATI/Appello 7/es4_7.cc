//Individuare i problemi presenti nel codice seguente e mostrare modifiche minimali per prevenirli:
#include <string>
#include <vector>
#include <iostream>
#include <algorithm> 
typedef std::vector<std::string> vect;
typedef std::vector<std::string>::iterator iter;

void f(const vect& v) {
 auto i = std::find(v.begin(), v.end(), "inizio");
 auto i_end = std::find(v.begin(), v.end(), "fine");
 while (i != i_end && i<i_end) {
    std::cout << *i << std::endl;
    ++i;
 }
}
void g(vect& v) {
    iter i = v.begin(), i_end = v.end();
    i=v.insert(++i, "prima");
    i=v.insert(++i, "dopo");
    i=v.begin();
    while (i != v.end()) {
    std::cout << *i << std::endl;
    ++i;
 }

}

int main(){
    vect c={"fine", "inizio"};
    f(c);
    g(c);
    return 0;
}