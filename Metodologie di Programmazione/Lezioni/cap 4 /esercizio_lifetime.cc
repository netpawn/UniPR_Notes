#include <iostream> 
using namespace std; 
//---------------------------------------
struct C1{
    int i1; 
    C1(){
        cerr << "Constructor C1::C1()" << endl; 
    }
    ˜C1(){
        cerr << "Destructor C1::˜C1()" << endl; 
    }
};
//---------------------------------------
struct C2{
    int i2;
    C2(){
        cerr << "Constructor C2::C2()" << endl;
        throw 123; 
    }
    ˜C2(){
        cerr << "Destructor C2::˜C2()" << endl; 
    }
};
//---------------------------------------
struct C3 : public C1{
    int i3; 
    C3(){
        cerr << "Constructor C3::C3()" << endl; 
    }
    ˜C3(){
        cerr << "Destructor C3::˜C3()" << endl; 
    }
};
//---------------------------------------
//D:{C1 :{i1}, i4, c3:c3{C1:{i1}, i3}, C2:C2{i2}, C1:c1{i1}}

class D : public C1{
    private: 
    int i4; 
    C3 c3; 
    C2 c2; 
    C1 c1; 

    public: 
    D() : c1(), c2(), c3() {
        cerr << "Constructor D::D()" << endl; 
    }
    ˜D() { 
        cerr << "Destructor D::˜D()" << endl; 
    }
}; 
//---------------------------------------
C3 c3; 
//---------------------------------------

int main (){
    cout << "Start" << endl; 

    try{
        C1 c1; 
        D d;
    }catch (char c){
        cerr << "char " << endl; 
    }catch(...){
        cerr << "..." << endl;
    }cout << "end" << endl; 
    return 0; 
}

//---------------------------------------
C1 c1; 