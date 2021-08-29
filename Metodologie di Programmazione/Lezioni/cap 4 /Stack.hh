#ifndef exception_safe_stack_hh_include guard
#define exception_safe_stack_hh_include guard 1

include "Elem.hh"

#include <cassert> 
#include <cstddef>
#include <string> 


class Stack{
    public: 
    //tipo intera senza segno x dim
    typedef std::size_t size_type;
    //il tipo dei valori nello stack
    typedef Elem value_type; 
    //costr default 
    explicit Stack(size_type capacity = 16);
    //distr nothrow 
    ~Stack(); 
    //costr copia 
    Stack(const Stack& y); 
    //ass x copia 
    Stack& operator=(const Stack& y); 
    //costr di spost nothrow 
    Stack(Stack&& y); 
    //ass x spost nothrow 
    Stack& operator=(Stack&& y); 
    void swap(Stack& y); 
    void push(const value_type& elem);
    void pop(); 
    bool is_empty();

    value_type& top(); 
    const value_type& top() const;
    size_type size() const; 
    bool check_inv(); 


    private: 
    value_type* vec_;
    size_type capacity_; 
    size_type size_; 
    static value_type* make_copy(const value_type* src,
                                size_type src_size,
                                size_type dst_capacity);
    

    

};

#endif
