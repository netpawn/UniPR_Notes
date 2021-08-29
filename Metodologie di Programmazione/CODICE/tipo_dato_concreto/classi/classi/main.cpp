//
//  main.cpp
//  classi
//
//  Created by Tommaso Pellegrini on 07/09/2020.
//  Copyright © 2020 Tommaso Pellegrini. All rights reserved.
//


// //////////////// DOCUMENTAZIONE CLASSI ////////////////// //
/*
 
 
 CLASSES:
 
 C++ is an object-oriented programming language.

 Everything in C++ is associated with classes and objects, along with its attributes and methods. For example: in real life, a car is an object. The car has attributes, such as weight and color, and methods, such as drive and brake.

 Attributes and methods are basically variables and functions that belongs to the class. These are often referred to as "class members".

 A class is a user-defined data type that we can use in our program, and it works as an object constructor, or a "blueprint" for creating objects.
 
 
 class MyClass {       // The class
   public:             // Access specifier
     int myNum;        // Attribute (int variable)
     string myString;  // Attribute (string variable)
 };
 
 int main() {
   MyClass myObj;  // Create an object of MyClass

   // Access attributes and set values
   myObj.myNum = 15;
   myObj.myString = "Some text";

   // Print attribute values
   cout << myObj.myNum << "\n";
   cout << myObj.myString;
   return 0;
 }
 
 
 
 METODI:
 
 Methods are functions that belongs to the class.

 There are two ways to define functions that belongs to a class:

 Inside class definition
 Outside class definition
 In the following example, we define a function inside the class, and we name it "myMethod".

 Note: You access methods just like you access attributes; by creating an object of the class and by using the dot syntax (.):
 
 ENCAPSULATION:
 
 The meaning of Encapsulation, is to make sure that "sensitive" data is hidden from users. To achieve this, you must declare class variables/attributes as private (cannot be accessed from outside the class). If you want others to read or modify the value of a private member, you can provide public get and set methods.
 
 */

#include <iostream>
using namespace std;

class Car{
public:
    string marca;
    int targa;
    float dimensione;
    
    
    void metodocar(){
        cout << "chiamo il metodo stampa "
        << marca << " " << targa << " " << dimensione << endl;
    }
    
};

class Bici{
public:
    string marca;
    int codice;
    float dimensione;
    Bici(string x, int y, float z){
        marca = x;
        codice = y;
        dimensione = z;
    }
    
    void metodobici(){
        cout << "chiamo il metodo stampa "
        << marca << " " << codice << " " << dimensione << endl;
    }
    
};

class pezzodimerda{
public:
    string nome;
    string cognome;
    int age;
    
    pezzodimerda(string x, string y, int z){
        nome = x;
        cognome = y;
        age = z;
    }
    
    void metodopezzodimerda(){
        cout << "chiamo il metodo stampa "
        << nome << " " << cognome << " " << age << " " << salario << endl;
    }
    
    void setter(int s){
        salario = s;
    }
    int getter(){
        cout << "salario= " << salario << endl;
        return salario;
    }
    
private:
    int salario;
    
    
    
};


void stampa(Car c){
    cout << c.marca << " " << c.targa << " " << c.dimensione << endl;
}
void stampa(Bici b){
    cout << b.marca << " " << b.codice << " " << b.dimensione << endl;
}
void stampa(pezzodimerda p){
    cout << p.nome << " " << p.cognome << " " << p.age << " " << endl;
}

int main() {
    
    cout << "Begin testing"<< endl;
    
    Car car1;
    car1.marca = "bmw";
    car1.targa = 1923;
    car1.dimensione = 1.4;
    
    Bici bici1("boh", 123, 0.4);

    stampa(car1);
    stampa(bici1);
    car1.metodocar();
    bici1.metodobici();
    
    
    pezzodimerda merda1("luca", "angelini", 13);
    merda1.setter((1000));
    merda1.getter();
    
    merda1.metodopezzodimerda();
    stampa(merda1);
    
    cout << "End testing" << endl;
    return 0;
}
