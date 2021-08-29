//La seguente implementazione della classe Container, indipendentemente da quali siano le funzionalità che tale tipo di dato deve fornire, è errata. Individuare i problemi, indicando la sequenza di operazioni che porta alla loro occorrenza. Modificare la classe per eliminare tutti i problemi identificati. Discutere (brevemente) se la soluzione proposta è corretta anche in presenza di eccezioni.

template <typename T>
class Container {
public:
Container(int size)
 : sz(size), ps(new T[sz]) { //se avviene un errore nell'allocazione della memoria quellla già allocata non verrà eliminata
}
~Container() {
delete ps;
}
private:
 T* ps;
 unsigned int sz;
};

//versione con try catch
template <typename T>
class Container {
public:
Container(int size)
 : sz(size),ps(nullptr)) {
 try{
   ps=(new T[sz]);
 }
 catch(...){
  delete [] ps;
  throw;
}
~Container() {
delete [] ps;
}
private:
 T* ps;
 unsigned int sz;
};


//versione con smart pointer
template <typename T>
class Container {
public:
Container(int size)
 : sz(size),ps(new T[sz]) );

~Container() =default;

private:
 std::unique_ptr<T> ps;
 unsigned int sz;
};

