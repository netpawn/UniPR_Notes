#include <iostream>
#include <string>
using namespace std;

/*
con class possiamo definire l'interfaccia di una classe composta da metodi e proprietà
che gli oggetti andranno a mettere a disposizione all'esterno. Di norma la definizione
di una classe (interfaccia) si mette in un file header.h, la implementazione in .cpp.

con template
*/

class Object {
public:
    int objNum; //attributo, numero dell'oggetto
    string objStr; // attributo, stringa dell'oggetto

    void printa(){ //f per printare contenuto dell'oggetto
        cout << objNum << " " << objStr;
        return;
    }
};

class Car {
public:
    int anno;
    string modello;
    string targa;

    Car(int a, string m, string t){
        a = anno;
        m = modello;
        t = targa;
    }

    void printinfo(){
        cout << "anno: " << anno << " " << "modello: " << modello << " "
        << "targa: " << targa << endl; 
    }
};


int main(){
    Object o1; //creo un oggetto o1 di classe oggetto
    o1.objNum = 1; //il numero dell'oggetto è 1
    o1.objStr = "Ciao"; //la stringa dell'oggetto è Ciao.
    o1.printa(); // printo gli attributi del mio oggetto.
    Car c1 (1990, "BMW", "SIMP");
    c1.printinfo();
    c1.modello = 0001;
    cout << c1.modello << endl;


    return 0;
}
