#include <iostream>
#include <string>
#include <stack>
using namespace std;

//template di funzione
template <typename T>
T getmax (T a, T b){
    T result;
    result = (a>b)? a:b;
    return (result);
}

//template di classe
template <class T>
class mypair{
    T a, b;
public:
    mypair(T first, T second){
        a=first; b=second;
    }
    T getmassimo(); //dichiarazione (sola) della funzione getmax
};

template <class T> //definizione della funzione getmax
T mypair<T>::getmassimo(){
    T retval;
    retval = a>b? a:b;
    return retval;
}

//specializzazione su template di classe

template <class B> //questo è il template di classe base
class mycontainer{
    B element;
public:
    mycontainer (B arg){
        element = arg;
    }
    B increase (){
        return ++element;
    }
};

template<> //questa è la specializzazione per il template di classe per
           //funzionare con i char in particolare e non solo tipi T
class mycontainer <char>{
    char element;
public:
    mycontainer (char arg){
        element = arg;
    }
    char uppercase(){
        if ((element>='a')&&(element<='z'))
            element+='A'-'a';
            return element;
    }
};


int main() {
    cout << "template di funzione" << endl;
    int i=5, j=6; int k;
    long l=10, m=5; long n;
    k=getmax<int>(i,j);
    n=getmax<long>(l,m);
    cout << k << endl;
    cout << n << endl;
    cout << "template di classe" << endl;
    mypair<int> myobject (100, 75);
    cout << myobject.getmassimo();
    cout << "specializzazione di template (classe)" << endl;
    mycontainer<int> myint (7);
    mycontainer<char> mychar ('j');
    cout << myint.increase() << endl;
    cout << mychar.uppercase() << endl; 

    return 0;
}
