#include <iostream> 
#include "razionale.hh"

void foo(Razionale r); 
void foa(bool b); 


void test01(){
    Razionale r; //costruttore default

    Razionale r1(r);    //costtruttore copia 
    Razionale r2 = r;   //
    Razionale r3 {r};   // c++11
    Razionale r4 = {r}; // c++11

    Razionale r5(1, 2); //costruzione diretta 
    Razionale r6 {1, 2};//
    Razionale r7(1);    //
    Razionale r8{1};    //
    Razionale r9 = 1;   // implicita 

    r = r1; //ass x copia 
    r = Razionale(1); //ass x spost
    r2 = r1 = r; //concatenazione ass 

    r + r:  //op binari 
    r - r; 
    r * r; 
    r / r; 

    foo(true); 

    -r; //op unari 
    +r; 

    r += r; //op assign 
    r -= r; 
    r *= r; 
    r /= r; 

    ++r; //op increm decrem
    --r; 
    ++r;
    --r; 

    r == r; //op relazionali 
    r != r; 
    r < r; 
    r <= r; 
    r > r; 
    r >= r; 

    std::cin >> r; 
    std::cout << r << std::endl; 
    std::cout << r1 << "+" << r2 << "=" << (r1+r2) << std::endl; 
}