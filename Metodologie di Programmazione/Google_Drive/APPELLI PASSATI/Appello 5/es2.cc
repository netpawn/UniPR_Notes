//Indicare l’output prodotto dal seguente programma.

#include <iostream>
using namespace std;

class Base {
 public:
  Base() { cout << "Costruttore Base" << endl; }
  virtual void foo(int) { cout << "Base::foo(int)" << endl; }
  virtual void bar(int) { cout << "Base::bar(int)" << endl; }
  virtual void bar(double) { cout << "Base::bar(double)" << endl; }
  virtual ~Base() { cout << "Distruttore Base" << endl; }
};

class Derived : public Base {
 public:
  Derived() { cout << "Costruttore Derived" << endl; }
  void foo(int) { cout << "Derived::foo(int)" << endl; }
  void bar(int) const { cout << "Derived::bar(int)" << endl; }
  void bar(double) const { cout << "Derived::bar(double) const" << endl; }
  ~Derived() { cout << "Distruttore Derived" << endl; }
};

void g(Base b) {
 b.foo(5);
 b.bar(5.5);
}

int main() {
 Derived derived;
 Base base;
 Base& base_ref = base;
 Base* base_ptr = &derived;
 Derived* derived_ptr = &derived;
 cout << "=== 1 ===" << endl;
 base_ptr->foo(12.0);
 base_ref.foo(7);
 base_ptr->bar(1.0);
 derived_ptr->bar(1.0);
 derived.bar(2);
 cout << "=== 2 ===" << endl;
 base.bar(1);
 derived.bar(-1.0);
 derived.foo(0.3);
 base_ptr->bar('\n');
 cout << "=== 3 ===" << endl;
 g(*derived_ptr);
 return 0;
}


 Derived derived;
//Costruttore Base
//Costruttore Derived
 Base base;
//Costruttore Base
 Base& base_ref = base; //punta a ogg base
 Base* base_ptr = &derived; //punta a ogg base contenuto in derived
 Derived* derived_ptr = &derived; //punta a derived
 cout << "=== 1 ===" << endl;
 base_ptr->foo(12.0);
//Derived::foo(int)
 base_ref.foo(7);
//Base::foo(int)
 base_ptr->bar(1.0);
//base bar double
 derived_ptr->bar(1.0);
//Derived::bar(double) const
 derived.bar(2);
//Derived::bar(int)
 cout << "=== 2 ===" << endl;
 base.bar(1);
//Base::bar(int)
 derived.bar(-1.0);
//Derived::bar(double) const
 derived.foo(0.3);
//Derived::foo(int)
 base_ptr->bar(’\n’);
//Base::bar(int)
 cout << "=== 3 ===" << endl;
 g(*derived_ptr);//Costruttore di copia di Base
//Base::foo(int)
//Base::bar(double)

return
//Distruttore Base

//Distruttore Base
//Distruttore Derived
//Distruttore Base


*/
