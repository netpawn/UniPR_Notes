//La classe seguente contiene errori inerenti la corretta gestione delle risorse. Individuare almeno due 
//problemi logicamente distinti, indicando la sequenza di operazioni che porta alla loro occorrenza.
//Fornire quindi una soluzione alternativa e discutere brevemente i motivi per i quali tale soluzione
//si può ritenere corretta.

#include <string>
class A {
 int* pi;
 std::string str;    
 double* pd;
  public:
   A(const std::string& s) : pi(new int), str(s), pd(new double) { }
   ~A() { delete pi; delete pd; }
};
/*
#include <string>
class A {
    private:
     int* pi;
     std::string str;
     double* pd;
     A(const A&);
     operator=(const A&);
    public:
     A(const std::string& s) : pi(new int), str(s), pd(nullptr) {
         try{
             pd=new double;
         }
         catch(...){
             delete pi;
         }
      }
     ~A() { delete pi; delete pd; }
};
*/

int main(){
    A a ("ciao");
    A b=a;
    return 0;
}
