#ifndef GUARDIA_Razionale_h 1
#define GUARDIA_Razionale_hh 1
#include <iostream> 
#include <cassert>

class Razionale{
    public: 
    using Int = long; 
    
    // Razionale() = default; //costruttore def 
    //^ non usiamo più questo, ne creiamo uno
    Razionale() : num_(0), den(1) {
        assert(check_inv()); 
    }

    Razionale(const Razionale&)= default; //costr copia 
    Razionale& operator=(const Razionale&) = default; //ass x copia 
    Razionale(Razionale&&) = default; //costr x spost
    Razionale& operator=(Razionale&&) = default;//ass x spost 
    ˜Razionale()= default; //distruttore


    //noconv implicita - 2 arg costruttore
    explicit Razionale(Int n, Int d=1)
        :num_(n), den(d) {
            if(d==0){//nel caso di errore
                //segnala l'errore 
                throw DivByZero();  
            }
            assert(d!=0); //precondizione per usar costr (a carico del chiamante)
            normalize();
            assert(check_inv()); //postcondizione(invariante classe)

        }
    //

    //controllo dell' invariante
    bool check_inv() const; 



    Razionale operator-() const; 

    const Razionale& operator+() const{
        return *this; 
    }

    Razionale& operator +=(const Razionale& y){
        Razionale& x = *this; 
        assert(x.check_inv()); 
        assert(y.check_inv()); 
        //fare lavoro che mod x 
        assert(x.check_inv());    //controlliamo le inv in entrata sopra e poi uscita
        //assert(y.check_inv());  questa è ridondante
        return *this; 

    }
    Razionale& operator -=(const Razionale& y){
        Razionale& x = *this; 
        assert(x.check_inv()); 
        assert(y.check_inv()); 
        x.num_ = (x.num_ * y.den_ + y.num_ * x.den_); 
        x.den_ += y.den_;
        normalize();
        assert(x.check_inv());
        return *this; 
    }
    Razionale& operator *=(const Razionale& y);
    Razionale& operator /=(const Razionale& y);

    Razionale& operator++(){
        assert(check_inv());//precond inv class entrata
        num_ += den_; 
        assert(check_inv());//postcond inv class uscita
        return *this; 
    } //pre incremento 
    Razionale& operator--(){
         assert(check_inv());//precond inv class entrata
        num_ -= den_; 
        assert(check_inv());//postcond inv class uscita
        return *this;
    } //pre decremento

    
    
    Razionale operator++(int){
        assert(check_inv());
        Razionale& x = *this; 
        Razionale res = x; 
        assert(check_inv());
        +xx;
        return res; 
    } //post incremento

    Razionale operator--(int){
        Razionale res = *this; 
        operator--(); 
        return res; 
    }//post decremento 

    bool operator==(const Razionale& y)const; 
    bool operator<(const Razionale& y)const; 

    const Int& num() const { return num_ ; }
    const Int& den() const { return den_ ; }

    private:
    Int den_; 
    Int num_; 

};



inline Razionale 
operator+(const Razionale& x, const Razionale& y){
    Razionale res = x; 
    res += y;
    return res; 
}

inline Razionale 
operator-(const Razionale& x, const Razionale& y){
    Razionale res = x; 
    res -= y; 
    return res; 
}

inline Razionale 
operator*(const Razionale& x, const Razionale& y){
    Razionale res; 
    res *= y; 
    return res; 
}

inline Razionale 
operator/(const Razionale& x, const Razionale& y){
    Razionale res; 
    res /= y; 
    return res; 
}




//INOUT

std::ostream& operator<<(std::ostream& os, const Razionale& x); 

std::istream& operator>>(std::istream& is, const Razionale& x); 





#endif 