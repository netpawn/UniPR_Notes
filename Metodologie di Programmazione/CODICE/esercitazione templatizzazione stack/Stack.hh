#ifndef EXCEPTION_SAFE_STACK_HH_INCLUDE GUARD
#define EXCEPTION_SAFE_STACK_HH_INCLUDE GUARD 1

#include <cassert> 
#include <cstddef>
#include <string> 


template <typename T> 
class Stack { 
    public: 
    typedef std::size_t size_type; //tipo int x dim 
    typedef T value_tpye; //tipo val in stack
    using value_type = T; //stessa cosa nuovo modo 
    explicit Stack(size_type capacity = 16); //costr default
    ~Stack(); //Distruttore
    Stack(const Stack& y); //costr copia 
    Stack& operator=(const Stack& y); //ass copia 
    
}




#endif