//2
cand[1,2,3] utilizzabili [2,3] migliore [2]
//5
cand[4,5] util[5] migliore [5]



pb->f(); Derived::f()
pb2->f();
pb->g();
pb->h(); Base::h()  
pb2->h();


implementare:
transform: prende in input 2 seq, prende in input una funzione binaria
prende in input una seq di out, scorre elem x elem le prime due seq
applicando la funzione binaria a un elem della priam e della seconda
(stessa posizione) e il risultato della funzione binaria lo scrive in out
la seconda seq è sicuramente lunga almeno quanto la prima

#include <iostream>
#incldue <iterator>

template <typename S1, typename S2, typename S3, typename Funz>
transform(S1 s1i, S1 s1e, S2 s2i, S2 s2e, S3 out, Funz fb){
    for(; s1i != s1e; ++s1i){
        fb(s1i, s2i);
        s2i++;
        out >> fb;
    }
}
