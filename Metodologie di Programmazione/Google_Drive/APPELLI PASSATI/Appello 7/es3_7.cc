//Una libreria per il calcolo simbolico implementa alcune delle sue funzionalità essenziali (quali la stampa e la valutazione numerica delle espressioni simboliche) mediante codice come il seguente:
class Expr {
 public:
  enum Kind { VAR, CONST, ADD, SUB, /*...*/ };
  Kind kind;
  // ...
  void print() const {
   switch (kind) {
   case VAR:
     print(name());
     break;
   case CONST:
     print(value());
     break;
   case ADD:
     arg1().print();
     print(" + ");
     arg2().print();
     break;
   case SUB:
     arg1().print();
     print(" - ");
     arg2().print();
     break;
    /* ... */
   }
}

double eval(const Var_Bindings& vb) const {
  switch (kind) {
  case VAR:
    return vb[name()];
  case CONST:
    return value();
  case ADD:
    return arg1().eval(vb) + arg2().eval(vb);
  case SUB:
    return arg1().eval(vb) - arg2().eval(vb);
   /* ... */
  }
 }
// ...
}; //expr

//Nell’ipotesi che l’insieme dei possibili tipi di espressioni debba essere estendibile, enunciare il principio della programmazione orientata agli oggetti che viene violato e mostrare (brevemente) le conseguenze di questa violazione.

//Abbozzare una soluzione alternativa che rispetti il principio in questione, mostrando le modifiche da apportare al codice suddetto. Discutere brevemente se la soluzione proposta è anche in grado di garantire l’estendibilità dell’insieme di operazioni supportate dalla classe Expr.

class Var : public expr{
 void print(name()) const;
 double eval(const Var_Bindings& vb) const{
   return vb[name()];
 }
}     

class Const : public expr{
 void print(value()) const;
 double eval(const Var_Bindings& vb) const{
   return value();
 }
}    
 
class Add : public expr{
 void print (arg1,arg2) const{
  arg1().print();
  print(" + ");
  arg2().print();
 }
 double eval(const Var_Bindings& vb) const{
    return arg1().eval(vb) + arg2().eval(vb);
}
  
}     
class Sub : public expr{
void print (arg1,arg2) const{
 arg1().print();
 print(" - ");
 arg2().print();

double eval(const Var_Bindings& vb) const{
   return arg1().eval(vb) - arg2().eval(vb);
}
}
class Expr {
 public:
  Kind kind;
  // ...
  virtual void print() const=0;
 
  virtual double eval(const Var_Bindings& vb) const=0;
}; //expr

