//trovare e correggere errori

#include <string> 

class A{
    private:
    int* pi; 
    std::string str; 
    double* pd; 

    public: 
    A(const std::string& s)
     : pi(new int), str(s), pd(nullptr){
         try{//proteggo la risorsa *pi 
            pd = new double; 
        }catch(...){
            delete pi; 
            throw; 
        }
    
    }//se la prima new fallisce, non è un problema perché non c'era acquisizione
    //se invece la prima ha successo ma fallisce la seconda abbiamo un problema
    //pi non verrebbe distrutto, dobbiamo ritardare la allocazione della secodna ris
    
    A(const A& a)= delete; 
    A(A&& a)= delete; 
    //A& operator=(const A& a)= delete; 
    //A& operator=(A&& a)= delete; 
    
    
    ~A(){
        delete pi; 
        delete pd; 
    }

}