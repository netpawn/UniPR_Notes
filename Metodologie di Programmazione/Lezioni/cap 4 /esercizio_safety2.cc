#include <vector> 

template <typename T> 
class A{
    private:
    int i; 
    T* p; 
    double d; 

    public: 
    A():i(), p(new T), de(){

    }
    ~A(){
        delete p; 
    }
};

//-------------------------------------
template <typename T > 
class B{
    private:
    int i; 
    T* p; 
    double d; 

    //priv non impl. 
    B(const B&); 
    B& operator=(const B&); 

    public: 
    B(): i(100), p(new T[i], d() {}
    ~B(){delete[] p;}
};

//-------------------------------------

class C : private A<std::vector<int>> {
    private:
    B<double> b1; 
    B<int> b2; 

    //priv non impl 
    C(const C&); 
    C& operator=(const C&);

    public: 
    C(){}
}; 