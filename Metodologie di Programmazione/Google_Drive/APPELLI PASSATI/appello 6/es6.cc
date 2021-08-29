//Discutere brevemente sotto quali condizioni il codice seguente si può considerare exception safe:

void foo(Sched& v, Sched& w, unsigned n) {
 get_mutex_for(v);
 try {
  get_mutex_for(w);
  try {
   transmit(v, w, n);
   release_mutex_for(w);
   release_mutex_for(v);
  }
  catch (...) {
  release mutex_for(w);
  throw;
  }
 }
 catch (...) {
  release_mutex_for(v);
  throw;
 }
}
//Fornire una codifica alternativa basata sull’idioma “l’acquisizione di risorse è una inizializzazione”.
