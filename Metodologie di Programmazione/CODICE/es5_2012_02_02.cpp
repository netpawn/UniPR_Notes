#include <string>

class A {
private:
    int* pi;
    std::string str;
    double* pd;

A(const A&);
operator=(const A&); //dichiaro le 2 funz per evitare costruttori copia e spostamento

public:
A(const std::string& s) : pi(new int), str(s), pd(new double) {
    try{
        pd = new double;
    }catch(...){
        delete pi;
        throw;
    }
}
~A() { delete pi; delete pd; }

};
