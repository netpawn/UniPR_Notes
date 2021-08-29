//Per ognuna delle seguenti chiamate, dire se la risoluzione dell’overloading va a buon fine e, nel caso, indicare quale funzione viene effettivamente invocata.

void f(const char* s); // funzione #1

template <typename T>
void f(T t); // funzione #2

template <typename T>
void f(T t1, T t2); // funzione #3

template <typename T, typename U>
void f(T t, U u); // funzione #4

template <typename T>
void f(T* pt, T t); // funzione #5

template <typename T, typename U>
void f(T* pt, U u); // funzione #6

template <typename T>
void g(T t, double d); // funzione #7

template <typename T>
void g(T t1, T t2); // funzione #8

int test() {
 f('a'); // chiamata #1
 f("aaa"); // chiamata #2
 int i;
 f(i); // chiamata #3
 f(i, i); // chiamata #4
 f(i, &i); // chiamata #5
 f(&i, i); // chiamata #6
 double d;
 f(i, d); // chiamata #7
 f(&d, i); // chiamata #8
 long l;
 g(l, i); // chiamata #9
 g(l, l) ; // chiamata #10
 g(l, d) ; // chiamata #11
 g(d, d) ; // chiamata #12
}

/*
-- chiamata 1 
cand: 1,2,3,4,5,6 (1 no util: non esiste conv da caratt a punt a cost carattere)
util: 2
migliore: 2

-- chiamata 2 
cand: 1,2,3,4,5,6
util: 1,2
migliore: ambiguo ->tolgo funzione templatica-> 1

-- chiamata 3 
cand: 1,2,3,4,5,6
util: 2
migliore: 2

-- chiamata 4 
cand: 1,2,3,4,5,6
util: 3,4
migliore: 3 (più specifica)

-- chiamata 5 
cand:1,2,3,4,5,6
util: 4
migliore: 4

-- chiamata 6 
cand: 1,2,3,4,5,6
util: 4,5,6( f<int,int> (int*,int) )
migliore: 5

-- chiamata 7 
cand: 1,2,3,4,5,6,
util: 4
migliore: 4

-- chiamata 8 
cand: 1,2,3,4,5,6
util: 4,6
migliore: 6

-- chiamata 9 
cand: 7,8
util: 7
migliore: 7

-- chiamata 10 
cand: 7,8
util: 7,8
migliore: 8

-- chiamata 11 
cand: 7,8
util: 7
migliore: 7

-- chiamata 12 
cand: 7,8
util: 7,8
migliore: ambiguo

*/
