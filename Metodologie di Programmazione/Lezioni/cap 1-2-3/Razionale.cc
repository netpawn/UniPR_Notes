#include "razionale2.hh"
#include <numeric> 

std::ostream& 
operator<<(std::ostream& os, const Razionale& x){
    os << "(" << x.num() << "/" << x.den() << ")";
    return os;
}

void Razionale::normalize(){
    if(den < 0){
        num_ = -num_;
        den_ = -den_;
    }
    Int k = std::gcd(num_, den_);
    num_ /= k;
    den_ /= k;
}

bool Razionale::check_inv() const{
    //zero come 0/1
    if(num_ ==0)
        return den_ ==1; 
    //den strett positivo
    if(den_ <=0)
        return false; 
    //num e den coprimi
    return std::gcd(num_, den_) == 1; 
}

