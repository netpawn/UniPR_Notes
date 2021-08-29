//Mostrare il processo di risoluzione dell’overloading per le seguenti chiamate di funzione. Per ogni chiamata, indicare: l’insieme delle funzioni candidate; l’insieme delle funzioni utilizzabili; la migliore funzione utilizzabile (se esiste); il motivo di eventuali errori di compilazione.

void foo(int*); // Funzione #1
template <typename T>
void foo(const T&); // Funzione #2
template <typename T>
void foo(T, T); // Funzione #3
template <typename T, typename U>
void foo(T, U); // Funzione #4
template <typename T>
void foo(const T*, T);// Funzione #5
template <typename T, typename U>
void foo(T*, U); // Funzione #6

namespace A {

struct Delta {
 Delta(double = 0) {};
};

template <typename T>
void bar(T, double); // Funzione #7
template <typename T, typename U>
void bar(T, U); // Funzione #8
} // namespace A

template <typename T>
void bar(T, const A::Delta&); // Funzione #9

int main() {
 int alfa;
 const int* p_alfa = &alfa;
 double beta;
 long gamma;
 A::Delta delta;

 foo(&alfa, beta); // chiamata A
 foo(&alfa, alfa); // chiamata B
 foo(p_alfa, alfa); // chiamata C
 foo(alfa, p_alfa); // chiamata D

 foo(alfa); // chiamata E
 foo(&alfa); // chiamata F
 foo(p_alfa); // chiamata G
 foo(const_cast<int*>(p_alfa)); // chiamata H
 
 bar(gamma, gamma); // chiamata I
 bar(delta, alfa); // chiamata L
 bar(delta, beta); // chiamata M
 A::bar(beta, gamma); // chiamata N
}

/*
-- chiamata A --
cand: 1,2,3,4,5,6
util: 4,6
migliore: 6

-- chiamata B --
cand: 1,2,3,4,5,6
util: 4,5,6
migliore: 5

-- chiamata C --
cand: 1,2,3,4,5,6
util: 4,5,6
migliore: 5

-- chiamata D 
cand: 1,2,3,4,5,6
util: 4
migliore: 4

-- chiamata E --
cand: 1,2,3,4,5,6
util: 2
migliore: 2

-- chiamata F --
cand: 1,2,3,4,5,6
util: 1
migliore: 1

-- chiamata G 
cand: 1,2,3,4,5,6
util: 2
migliore: 2

-- chiamata H --
cand: 1,2,3,4,5,6
util: 1,2
migliore: 1

-- chiamata I --
cand: 9
util: 9
migliore: 9

-- chiamata L --
cand: 7,8,9
util: 7,8
migliore: 8

-- chiamata M --
cand: 7,8,9
util: 7,8
migliore: 7

-- chiamata N --
cand: 7,8
util: 7,8
migliore: 8

*/
