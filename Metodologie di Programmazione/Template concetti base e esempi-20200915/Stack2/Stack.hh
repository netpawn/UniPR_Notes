#ifndef EXCEPTION_SAFE_STACK_HH_INCLUDE_GUARD
#define EXCEPTION_SAFE_STACK_HH_INCLUDE_GUARD 1

#include <cassert>
#include <cstddef>
#include <string>
#include <iostream>

//! Una pila espandibile.
/*!
  Una struttura dati pila che si espande automaticamente al bisogno.
  L'implementazione assicura il livello <EM>strong</EM> di correttezza
  rispetto alle eccezioni, sotto le seguenti condizioni:
   - il tipo T fornisce il costruttore di default e l'operatore
     di assegnamento (per copia e per spostamento);
   - il distruttore di T non lancia eccezioni;
   - gli operatori di assegnamento di T sono exception safe;
*/

template <typename T>
class Stack {
public:
  //! Un tipo intero senza segno adatto per le dimensioni.
  typedef std::size_t size_type;

  //! Il tipo dei valori contenuti nello stack.
  using value_type = T;

  //! Costruttore di default.
  explicit Stack(size_type capacity = 16);

  //! Distruttore (livello nothrow).
  ~Stack();

  //! Costruttore di copia.
  Stack(const Stack& y);

  //! Assegnamento per copia.
  Stack& operator=(const Stack& y);

  //! Costruttore di spostamento (livello nothrow).
  Stack(Stack&& y);
  //! Assegnamento per spostamento (livello nothrow).
  Stack& operator=(Stack&& y);

  //! Scambio efficiente e senza eccezioni.
  void swap(Stack& y);

  //! Mette una copia di \p elem in cima alla pila.
  void push(const value_type& elem);

  //! Rimuove il primo elemento della pila.
  void pop();

  //! Test di stack vuoto.
  bool is_empty() const;

  //! Accesso in lettura/scrittura al primo elemento.
  /*!
    Si assume che la pila non sia vuota. In caso di pila vuota
    il comportamento è indefinito.
  */
  value_type& top();

  //! Accesso in sola lettura al primo elemento.
  /*!
    Si assume che la pila non sia vuota. In caso di pila vuota
    il comportamento è indefinito.
  */
  const value_type& top() const;

  //! Numero di elementi sullo stack.
  size_type size() const;

  //! Controlla l'invariante della classe.
  /*!
    \return
    <CODE>true</CODE> se l'invariante di classe è soddisfatta;
    <CODE>false</CODE>, altrimenti.

    Utile per il debugging.
  */
  bool check_inv() const;

private:
  //! Puntatore alla memoria che contiene la pila.
  value_type* vec_;

  /*! \brief
    La capacita' attuale della pila (ovvero, il numero di elementi
    allocati a partire dall'indirizzo \p vec_).
  */
  size_type capacity_;

  /*! \brief
    La dimensione attuale della pila (ovvero, il numero di elementi
    significativi memorizzati in \p vec_).
  */
  size_type size_;

  // Funzioni di supporto per la gestione corretta dell'allocazione risorse.
  static value_type* make_copy(const value_type* src,
                               size_type src_size,
                               size_type dst_capacity);
  static value_type* make_move(value_type* src,
                               size_type src_size,
                               size_type dst_capacity);
};

////////////////////////////////////////////////////////////////////////////

template <typename T> //bisogna ripetere il fatto che siamo in classe 
//templatica, perché abbiamo chiuso la classe poco sopra con ; 
inline
Stack<T>::Stack(const size_type capacity)
  : vec_(nullptr), capacity_(capacity), size_(0) {
  if (capacity_ > 0)
    vec_ = new value_type[capacity_];
  assert(check_inv());
}

template <typename T>
inline
Stack<T>::Stack(const Stack& y)
  : vec_(make_copy(y.vec_, y.size_, y.capacity_)),
    capacity_(y.capacity_),
    size_(y.size_) {
  assert(check_inv());
}


template <typename T>
inline
Stack<T>::Stack(Stack&& y) : Stack(0) {
  assert(y.check_inv());
  swap(y);
  assert(check_inv());
}

template <typename T>
inline
Stack<T>::~Stack() {
  delete[] vec_;
}

template <typename T>
inline void
Stack<T>::swap(Stack& y) {
  using std::swap;
  swap(vec_, y.vec_);
  swap(size_, y.size_);
  swap(capacity_, y.capacity_);
}

template <typename T>
inline Stack<T>&
Stack<T>::operator=(const Stack& y) {
  // Costruisco una copia di y e la scambio con this.
  Stack temp(y);
  swap(temp);
  return *this;
}

template <typename T>
inline Stack<T>&
Stack<T>::operator=(Stack&& y) {
  assert(check_inv() && y.check_inv());
  Stack temp(std::move(y));
  swap(temp);
  assert(check_inv());
  return *this;
}

template <typename T>
inline typename Stack<T>::size_type
Stack<T>::size() const {
  return size_;
}

template <typename T>
inline bool
Stack<T>::is_empty() const {
  return size() == 0;
}

template <typename T>
inline const typename Stack<T>::value_type&
Stack<T>::top() const {
  // NOTA: è responsabilità del chiamante assicurarsi che
  // lo stack contenga almeno un elemento.
  assert(size_ > 0);
  return vec_[size_ - 1];
}

template <typename T>
inline typename Stack<T>::value_type&
Stack<T>::top() {
  // NOTA: è responsabilità del chiamante assicurarsi che
  // lo stack contenga almeno un elemento.
  assert(size_ > 0);
  return vec_[size_ - 1];
}

template <typename T>
inline void
Stack<T>::pop() {
  // NOTA: è responsabilità del chiamante assicurarsi che
  // lo stack contenga almeno un elemento.
  assert(size_ > 0);
  --size_;
  assert(check_inv());
}

template <typename T>
inline void
Stack<T>::push(const value_type& elem) {
  if (size_ == capacity_) {
    // Devo espandere la struttura dati.
    size_type new_capacity = 2*size_ + 1;
    value_type* temp = make_move(vec_, size_, new_capacity);
    // Da qui (e fino alla fine del blocco) ho solo operazioni
    // che non possono lanciare eccezioni.
    delete[] vec_;
    vec_ = temp;
    capacity_ = new_capacity;
  }
  vec_[size_] = elem;
  ++size_;
  assert(check_inv());
}

template <typename T>
typename Stack<T>::value_type*
Stack<T>::make_copy(const value_type* src,
                 size_type src_size, size_type dst_capacity) {
  assert(dst_capacity >= src_size);
  if (dst_capacity == 0)
    return nullptr;
  // Allochiamo la risorsa.
  value_type* dst = new value_type[dst_capacity];
  try {
    // Proviamo a copiare gli elementi da `src' a `dest'.
    for (size_type i = 0; i < src_size; ++i)
      dst[i] = src[i];
  }
  catch (...) {
    // Qualcosa è andato storto.
    // Deallochiamo la risorsa ...
    delete[] dst;
    // ... e rilanciamo l'eccezione per essere neutrali.
    throw;
  }
  return dst;
}

template <typename T>
typename Stack<T>::value_type*
Stack<T>::make_move(value_type* src, size_type src_size, size_type dst_capacity) {
  assert(dst_capacity >= src_size);
  if (dst_capacity == 0)
    return nullptr;
  // Allochiamo la risorsa.
  value_type* dst = new value_type[dst_capacity];
  // Spostiamo gli elementi da `src' a `dest'.
  for (size_type i = 0; i < src_size; ++i)
    dst[i] = std::move(src[i]);
  return dst;
}

template <typename T>
bool
Stack<T>::check_inv() const {
  if (capacity_ == 0 && vec_ != nullptr) {
#ifndef NDEBUG
    std::cerr << "Lo Stack è dichiarato avere una capacità "
      "nulla ma ha risorse allocate!" << std::endl;
#endif // NDEBUG
    return false;
  }
  if (size_ > capacity_) {
#ifndef NDEBUG
    std::cerr << "Lo Stack è dichiarato avere una dimensione "
	      << "superiore alla capacità!" << std::endl;
#endif // NDEBUG
    return false;
  }
  if (capacity_ > 0 && vec_ == nullptr) {
#ifndef NDEBUG
    std::cerr << "Non vi sono risorse allocate per lo Stack!"
	      << std::endl;
#endif // NDEBUG
    return false;
  }
  // Tutto ok.
  return true;
}

#endif // EXCEPTION_SAFE_STACK_HH_INCLUDE_GUARD
