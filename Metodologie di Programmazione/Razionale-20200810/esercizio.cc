// La classe templatica Set è intesa rappresentare un insieme di elementi
// di tipo T. L'implementazione della classe si basa sulla manipolazione
// di liste ordinate (senza duplicati). L'interfaccia della classe
// presenta numerosi problemi. Cercare di individuarne il maggior numero
// ed indicare come possono essere risolti (modificando l'interfaccia).

template <typename T>
class Set : public std::list<T> {

public:
  Set();    // costruisce l'insieme vuoto.

  Set(T t); // costruisce il singoletto che contiene t.

  Set(Set y);            // costruttore copia
  void operator=(Set y); // assegnamento per copia

  unsigned size();       // numero di elementi contenuti

  bool is_empty();       // *this è l'insieme vuoto?

  bool contains(Set y);  // *this contiene y?

  T& min();              // restituisce l'elemento minimo contenuto

  void pop_min();        // elimina l'elemento minimo

  void insert(T z);      // inserisce l'elemento z (se non è già presente)

  // unione con assegnamento: *this = *this union y
  void union_assign(Set y);

  // intersezione con assegnamento: *this = *this union y
  void intersection_assign(Set y);

  void swap(Set y); // scambia *this con y

  std::ostream operator<<(std::ostream os); // stampa *this su os

private:
  // dettagli implementativi (non fanno parte dell'interfaccia)
};
