//Sia data la seguente definizione di classe templatica (dove si assume che le funzioni dichiarate siano state implementate correttamente):
#include <iostream>

template <typename T>
class Container {
 public:
  Container();
  Container(const Container& y);
  Container& operator=(const Container& y);
  ~Container();
private:
// ...
};

//Individuare gli errori nel codice seguente, indicandone il motivo.
int main(){
Container<int> ci1;
Container<int> ci2 = ci1;
Container<double> cd2 = ci1; 
Container<int> ci3;
Container<double> cd3;
ci3 = ci1; 
cd3 = ci1; 
return 0;
}

//Supponendo che il codice utente di cui sopra sia ritenuto valido, come occorre modificare la classe per correggere gli errori individuati?

template <typename T>
class Container {
 public:
  Container();
  template <typename U>
  Container(const Container<U>& y);
  template <typename U>
  Container& operator=(const Container<U>& y);
  ~Container();
private:
// ...
};

int main(){
Container<int> ci1;
Container<int> ci2 = ci1;
Container<double> cd2= ci1; //double int templatizziamo costruttore di copia
Container<int> ci3;
Container<double> cd3;
ci3 = ci1; 
cd3 = ci1; //double int templatizziamo operatore di assegnamento
return 0;
}

