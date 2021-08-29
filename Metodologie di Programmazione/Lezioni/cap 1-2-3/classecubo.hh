#include <iostream> 

class cubo{
    public:

    cubo(){
        std::cout << "costruttore chiamato" << std::endl; 
    }; //def
    cubo(const cubo&){
        std::cout << "costruttore copia" << std::endl; 
    }; //copia 
    cubo& operator=(const cubo&){
        std::cout << "ass copia" << std::endl; 
    }; //ass copia
    int lato; 

};