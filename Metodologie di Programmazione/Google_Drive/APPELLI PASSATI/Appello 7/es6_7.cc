//Il codice seguente contiene errori inerenti la corretta gestione delle risorse. Individuare almeno due problemi logicamente distinti, indicando la sequenza di operazioni che porta alla loro occorrenza. Fornire quindi due soluzioni alternative, rispettivamente con e senza applicazione dell’idioma RAII (“l’acquisizione di risorse è una inizializzazione”). Infine discutere brevemente i motivi per i quali le soluzioni fornite possono ritenersi corrette.

#include <memory>
//struct C { ~C() {} /* ... */ };
//struct D : public C { /* ... */ };
/*void job(const C* pc1, const C* pc2){}
void foo() {
 C* pc = new D(); //pc st=C punta a D
 job(pc, new C()); //allocato C e passato a pc2. pc2 esce da blocco->eliminato unico punt a memoria-> no deallocata memoria. se allocazione di C va male -> pc no eliminato
 delete pc;
}


//struct C { ~C() {} /* ... */ //};
//struct D : public C { /* ... */ };
/*void job(const C* pc1, const C* pc2){}
void foo() {
 C* pc = new D(); //pc st=C punta a D 
 try{
 C* pk= new C();
    try{
     job(pc, pk); 
    }
    catch(...){
     delete pk;
     throw;
    }
    delete pk;
    delete pc;
 }
 catch(...){
   delete pc;
   throw;
 }
}

*/
struct C { ~C() {} /* ... */ };
struct D : public C { /* ... */ };
void job(const C* pc1, const C* pc2){}
void foo() {
 std::unique_ptr<D> pc (new D());
 //pc= std::make_unique<D>()
 std::unique_ptr<C> pk (new C());
 //pk= std::make_unique <C> ();
 job(pc.get(), pk.get()); 
}

int main(){
foo();
}


