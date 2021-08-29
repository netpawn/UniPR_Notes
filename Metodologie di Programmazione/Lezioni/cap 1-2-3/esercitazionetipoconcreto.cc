//la classe templatica Set è intesa a rappresentare un insieme di elementi 
//di tipo T. L'implementazione della classe si basa sulla manipolazione di liste
//ordinate senza duplicati. L'interfaccia della classe ha numerosi problemi. 
//Vanno trovati e risolti (modificando l'interfaccia)

template <typename T> 
//class Set: public std::list<T>{
class Set: private std::list<T>{
    private: 
    //dettagli implementativi (no interfaccia)

    public: 
    Set(): //costruisce insieme vuoto 
    
    Set(T t); //costruisce il singoletto che contiene t
    Set(const T& t); 


    Set(Set y); //costruttore copia 
    Set(const Set& y);
    
    void operator=(Set y); //ass x copia 
    Set& operator=(const Set& y);

    unsigned size(); //n elemes contenuti 
    unsigned size() const; 
    
    bool is_empty(); //*this è l'insieme vuoto? 
    bool is_empty() const; //non mi serve l'accesso in scrittura! 
    
    bool contains(Set y); //*this contiene y? 
    bool contains(constt Set y) const; //setsso motivo di quello sopra. copia inutile
    
    T& min(); //return min elem
    const T& min() const; //non voglio modifcare il min / invariante classe 
    
    void pop_min(); //pops min 
    
    void insert(T z); //inserisce elem z se non presente
    void insert(const T& z); //non voglio modificare

    //unione con assegnamento: *this = *this union y
    void union_assign(Set y); 
    void union_assign(const Set& y);//const interno per non modificare y ma non esterno

    //intersezione con assegnamento: *this = *this union y
    void intersection_assign(Set y); 
    void interscetion_assing(const Set& y); //same 

    void swap(Set y); //scambia *this con y 
    void swap(Set& y); //mi serve passaggio per riferimento modificabile 
    
   


};


//NB: VA FUORI DALLA CLASSE 
 std::ostream operator<<(std::ostream os); //stampa *this su us
 template <typename T> 
 std::ostream& 
 operator<<(std::ostream& os, const Set<T>& s){
     s.print(os);
     return os; 
 } //non voglio modificare quel che stampo 



void foo(const Set<std::string>& s){
    std::cout << s.size(); 
}//match perfetto se lascio const su size() 

void foos(const Set<std::string>& s){
    std::cout << s << s
}