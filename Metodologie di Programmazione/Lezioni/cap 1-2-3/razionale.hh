#ifndef GUARDIA_Razionale_hh
#define GUARDIA_Razionale_hh 1 

#include <iostream>


class Razionale{
    public: 
    
    Razionale(); 
    //costruttore di default 
    
    Razionale(const Razionale&); //costruttore di copia 
    //^ se lo dichiaro, dico al compilatore che lo voglio io, altrimenti aggiungo = default; 
    
    Razionale(const Razionale&&); //rvalue mod quindi && 
    //costruttore per spostamento 

    Razionale& operator=(const Razionale&);  
    //assegnamento per copia 

    Razionale& operator=(Razionale&&) = default; 
    //assegnamento per spostamento
    
    ˜Razionale()= default; 
    //distruttore
    
    // Quelli sopra vengono tutti forniti di default dal compilatore 


    using Int = long;  //alias di tipo 

    Razionale(Int n, Int d); //per costruire il razionale con nom e denom (err)
    
    explicit Razionale(Int n, Int d=1); //per costruire usando un solo intero (err)
    //operatore di conversione implicita da long -> razionale
    //è meglio evitarla? forse. Possiamo marcarlo explicit per evitare l'implicita da long -> raz, ma dovrei aggiungere la costr esplicita. 
    //è probabilmente meglio marcare le conversioni come explicit. 


    //tutti gli operatori aritmetici binari danno errore. Vanno definiti
    
    Razionale& operator+=(const Razionale& y); 
    Razionale operator+(const Razionale& y) const{
        Razionale res = *this; 
        res += y; 
        return res; 
    }//implementazione dell'operator+ 
    //questa implementazione si può anche spostare al di fuori della classe, ma non ha più 
    //il this, quindi va esplicitato il primo argomento const Razionale& x, const Razionale& y
    // e poi Razionale res = x; A livello metodologico è meglio definire l'operatore fuori dalla classe, anche perché non essendo friend, 
    //nella sua definizione non usa "trucchi" per accedere ala classe. Ovvero -> la classe non funziona bene? Sicuramente non è colpa di questa implementazione 
    
    Razionale& operator+=(const Razionale& y); 
    Razionale& operator-=(const Razionale& y);
    Razionale& operator*=(const Razionale& y);
    Razionale& operator/=(const Razionale& y);


    //operatori unari 

    Razionale operator+() const; 
    const Razionale& operator-() const{
        return *this;
    } //tiny optimization 
    Razionale operator*();
    Razionale operator/();
    
    //operatori incrementali 
    Razionale& operator++(); //pre incremento
    Razionale& operator--(); //pre decremento

    Razionale operator++(int){
        Razionale res = *this; 
        operator++(); //incremento
        return res; //do quello precedente all'incremento
    } //post incremento  ////regola -> int come finto argomento fittizio per differire dall'altra funzione
    Razionale operator--(int){
        Razionale res = *this; 
        this->operator--(); //Stessa cosa di quella sopra 
        return res; 
    } //post decremento  ---> same 


    //operatori di confronto 
    bool operator==(const Razionale& y) const; 
    bool operator!=(const Razionale& y) const; //di norma implementato fuori perché fa come gli operatori aritmetici 
    /* 
    inline Razionale
    operator!=(const Razionale& x, const Razionale& y){
        return !(x==y);
    }
    */ 
    bool operator <(const Razionale& y) const; 
    //fuori posso negare il < per definire il < e il <= 



    //INPUT E OUTPUT 
    //DEVONO ESSERE ESTERNI ALLA CLASSE! 

    private: 
    Int num; 
    Int den; 


};//class razionale 

//altri operatori fuori classe 
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
    Razionale res = x; 
    res *= y; 
    return res; 
}

inline Razionale 
operator/(const Razionale& x, const Razionale& y){
    Razionale res = x; 
    res /= y; 
    return res; 
}


inline bool 
operator<=(const Razionale& x, const Razionale& y){
    return !(x>y); 
}

inline bool 
operator<=(const Razionale& x, const Razionale& y){
    return (x==y) || (x<y); 
}



//INOUT

std::ostream& operator<<(std::ostream& os, const Razionale& x); 

std::istream& operator>>(std::istream& is, const Razionale& x); 



// \\D O N E//
//  \\     //
//   \\   //
//    \\_//
//     \_/


#endif // GUARDIA_Razionale_hh 1 



/////////NOTE: 
/*
- Tra struct e class l'unica vera differenza è che la struct non ha differenza fra public e private. 
-
*/