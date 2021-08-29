#include <iostream>
using namespace std;
struct A {
  virtual void f(int)    { cout << "A::f(int)" << endl; }
  virtual void f(double) { cout << "A::f(double)" << endl; }
  virtual void g() { cout << "A::g(double)" << endl; }
virtual ~A() { cout << "Destructor A::~A()" << endl; } };

struct B : public A {
  void f(int) { cout << "B::f(int)" << endl; }
  virtual void f(double) const { cout << "B::f(double)" << endl; }
  virtual void g(int) { cout << "B::g(int)" << endl; }
~B() { cout << "Destructor B::~B()" << endl; } };

struct C : public B {
  void f(int) const { cout << "C::f(int)" << endl; }
  void g(int) { cout << "C::g(int)" << endl; }
~C() { cout << "Destructor C::~C()" << endl; } };

int main() {
A* a = new A; cout << "1" << endl;
B b; cout << "2" << endl;
C c; cout << "3" << endl;
A& ra_b = b; cout << "4" << endl;
B& rb_b = b; cout << "5" << endl;
A& ra_c = c; cout << "6" << endl;
B& rb_c = c; cout << "7" << endl;
cout << "=== 1 ===" << endl; ra_b.f(1); cout << "8" << endl;
rb_b.g(1); cout << "9" << endl;
ra_c.f(1); cout << "10" << endl;
rb_c.g(1); cout << "11" << endl;
cout << "=== 2 ===" << endl;
static_cast<A*>(&b)->f(1.2);
static_cast<A*>(&c)->f(1);
static_cast<B*>(&c)->g(1.2);
cout << "=== 3 ===" << endl;
b.f(2); cout << "12" << endl;
c.g(3); cout << "13" << endl;
cout << "=== 4 ===" << endl;
cout << "14" << endl;
}


/*
===1===
B::f(int)
B::g(int)
B::f(int)
C::g(int)
===2===
A::f(double)
B::f(int)
C::g(int)
===3===
B::f(int)
C::g(int)
===4===
distruttori ->
Destructor C::~C()
Destructor B::~B()
Destructor A::~A()
Destructor B::~B()
Destructor A::~A()
*/
