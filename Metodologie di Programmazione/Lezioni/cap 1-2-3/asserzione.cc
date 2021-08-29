//sono costrutti che verificano se una 
//determinata espressione valuta sempre a vero 
//di base non serve ma è un safety check che mi serve 
//per fare eventuali ottimizzazioni. 

//Si usa normalmente in fase di debugging  

#include <cassert> 
#include <iostream> 

int main(){
    double d = 2.0; 
    //altri calcoli che modficano d 
    double quadrato = d * d; 

    //assert expr-> termina se expr valuta a false
    assert(quadrato >=0);

    std::cout << quadrato << std::endl; 
}