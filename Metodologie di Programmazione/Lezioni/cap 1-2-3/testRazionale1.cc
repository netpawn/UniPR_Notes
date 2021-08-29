#include "razionale2.hh"
#include <iostream>
#include <sstream> 

bool test1(){
    std::stringstream ss; //al posto di streammare su standard out lo fa su una stringa 
    Razionale zero; 
    ss << zero; 

    const std::string obtained = ss.str(); 
    const std::string expected = "(0/1)";

    if(obtained == expected) 
        return true; 
    
    std::cout << "test fallito" << std::endl; 
              << "obtained" << obtained << std::endl; 
              << "expected" << expected << std::endl; 

    return false; 
}

bool test2(){
    std::stringstream ss;
    Razionale one(1, 1);
    ss << one; 

    const std::string obtained = ss.str(); 
    const std::string expected = "(1/1") 
    
    if(obtained == expected) 
        return true;

    std::cout << "test2 fallito" << std::endl; 
              << "obtained" << obtained << std::endl; 
              << "expected" << expected << std::endl;
}

bool test3(){
    std::stringstream ss;
    Razionale r(4, 2);
    if(!r.check_inv())
        std::cout<<"invariante di classe rotta\n"; 
    ss << r; 

    const std::string obtained = ss.str(); 
    const std::string expected = "(2/1") 
    
    if(obtained == expected) 
        return true;

    std::cout << "test3 fallito" << std::endl; 
              << "obtained" << obtained << std::endl; 
              << "expected" << expected << std::endl;
}

bool test4(){
    std::stringstream ss;
    Razionale r(4, 0);
    if(!r.check_inv())
        std::cout<<"invariante di classe rotta\n"; 
    ss << r; 

    const std::string obtained = ss.str(); 
    const std::string expected = "ha sbagliato l'user") 
    
    if(obtained == expected) 
        return true;

    std::cout << "test4 fallito" << std::endl; 
              << "obtained" << obtained << std::endl; 
              << "expected" << expected << std::endl;
}

int main(){
    bool ok = true; 
    ok = ok && test1();

    ok = ok && test2();

    ok = ok && test3();
    
    ok = ok && test4();

    return ok ? 0 : 1; 
}

//tutto ciò verifica la funzionalità del costruttore di default
//bisogna linkare anche il file oggetto Razionale.o che viene da Razionale.cc 
//in questo caso tutto avrà successo 