#include <iostream>

// -----------------------------

void foo(const char* s) { std::cout << "funzione #1\n"; }

template <typename T>
void foo(T t) { std::cout << "template di funzione #2\n"; }

template <typename T>
void foo(T t1, T t2) { std::cout << "template di funzione #3\n"; }

template <typename T, typename U>
void foo(T t, U u) { std::cout << "template di funzione #4\n"; }

template <typename T>
void foo(T* pt, T t) { std::cout << "template di funzione #5\n"; }

template <typename T, typename U>
void foo(T* pt, U u) { std::cout << "template di funzione #6\n"; }

/*
  Ordinamento parziale dei template di funzione:
   - #3 è più specifico di #4
   - #5 è più specifico di #4
   - #6 è più specifico di #4
   - #5 è più specifico di #6
*/

// -----------------------------

template <typename T>
void bar(T t, double d) { std::cout << "template di funzione #7\n"; }

template <typename T>
void bar(T t1, T t2) { std::cout << "template di funzione #8\n"; }

// -----------------------------

int main() {
  foo('a');    // #2: foo<char>(char)
  foo("aaa");  // #1: foo(const char*)

  int i = 0;
  foo(i);      // #2: foo<int>(int)
  foo(i, i);   // #3: foo<int>(int, int)
  foo(i, &i);  // #4: foo<int, int*>(int, int*)
  foo(&i, i);  // #5: foo<int>(int*, int)

  double d = 0.0;
  foo(i, d);   // #4: foo<int, double>(int, double)
  foo(&d, i);  // #6: foo<double, int>(double*, int)

  short s = 0;
  bar(i, d);   // #7: bar<int>(int, double)
  bar(i, i);   // #8: bar<int>(int, int)
  bar(i, s);   // #7: bar<int>(int, double)
  bar(d, d);   // ambigua
}
