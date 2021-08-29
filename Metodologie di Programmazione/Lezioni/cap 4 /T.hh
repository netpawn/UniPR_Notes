class T{
    private:
    //dati (risorse)
    int a; 
    int b; 
    int* p;
    int* q;  

    public: 
    //ctor e dtor 
    //T()= default; 
    T(): p(new int(42)){}


   // ~T()= default(); 
    ~T()= default{
        delete p;
    }

    //copia 
   //T(const T&)= default; 
   //T& operator=(const T&) = default;

   // T(const T&) = delete; 
    //copia deep 
    T(const T& t) : a(t.a), p(new int(*t.p)){}
    
   // T& operator=(const T&) = delete;  
   /* T& operator=(const T&){
        delete p; 
        a = t.a;  
        p = new int(t.p);
        return *this; 
    } */ 
    T& operator=(const T&){
            T tmp(t);  
            swap(tmp); 
            return *this; 
        }



    //spostamento
    //T(T&&) = default; 
    //T& operator=(T&&) = default; 

    T(T&& t) : a(t.a), p(t.p){
        t.p = nullptr; 
    }
    T& operator=(T&& t){
        delete p; 
        a = t.a; 
        p = t.p; 
        t.p = nullptr; //avrebbe causato mem leak 
        return *this; 
    }


    void swap(T& t2){
        auto& t1=*this; 
        using std::swap; 
        swap(t1.a, t2.a);
        swap(t1.p, t2.p); 
    }

};   

//se i nostri dati sono dei tipi built in o forniti dall'utente (ma che 
//forniscono una corretta gestione delle risorse), allora in questo caso 
//le funzioni fornite dal compilatore si comportano in maniera corretta.
//Se dovessimo però (x es) mettere un puntatore, avremmo bisogno di una 
//gestione ad hoc, tipo il distruttore di default che non va bene, perché 
//se int* p stava puntando a una risorsa, allora questa va rilasciata. 

//se dobbiamo curare una sola risorsa riusciamo ad evitare dei blocchi try catch
//se però avessimo più risorse da curare questo non sarebbe possibile 