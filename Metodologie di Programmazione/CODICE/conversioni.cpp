#include <iostream>
#include <string>

//---------------------//
//Nessuna conversione, i tipi corrispondono.
//anche detti perfect match

int perfect_match(int i){
    std::cout << i << " E' un perfect match" << std::endl;
    return i;
};

//---------------------//
//CORRISPONDENZE ESATTE:
//implicite, conservano il valore dell'argomento
//L-Value to R-Value, Qualificazioni

void lrvalue(std::string s){
    std::cout << s << " è un una conversione lvalue -> rvalue" << std::endl;
    return;
};

void lrvalue2(int a, int b){
    int c;
    c = a + b; //l'operatore + richiede una conversione da Lvalue a Rvalue
    std::cout << c << " è un'altra conversione lvalue -> rvalue" << std::endl;
    return;
};

bool qualificazione(const int *a, int *b){
    if(*a > *b){
        std::cout << "qualificazione con check maggiore, true" << std::endl;
        return true;
    }else return false && std::cout << "ERRORE";
};

//---------------------//
// PROMOZIONI //
//Corrispondenza per promozione. Se il tipo dell'argomento non corrisponde,
//allora lo andiamo a promuovere. Abbiamo da:
//bool, char, uns char, short -> int || uns short -> int, uns int || float -> double
void promozione(unsigned int i){
    std::cout << i << " Promozione da unsigned short a int" << std::endl;
    return;
};

void promozione2(int i){
    std::cout << i << " Promozione da bool a int" << std::endl;
    return;
}

//---------------------//
//CONVERSIONE STANDARD:
//i tipi non corrispondono ne esattamente ne per promozione.
//Conversioni intere
//Conversioni in virgola mobile
//Conversioni in vm intero
//Conversioni da puntatori
//Conversioni booleane

void conversioneintera(int i){
    std::cout << i << " è intero, ma mi hai passato un float" << std::endl;
};
bool conversionebooleana(bool i){
    return true &&
    std::cout << i << " è vero, ma mi hai passato 1 e non true" << std::endl;
};


//---------------------//
//Conversione definita dall'utente
//sono operator oppure da razionale a razionale
//[...]

int main(){

int i=1;
perfect_match(i);
std::string color("rosso");
lrvalue(color);
int a = 5; int b = 2;
lrvalue2(a, b);//qui abbiamo corrispondenza esatta con conversione
qualificazione(&a,&b);//stampa true, effettua conversione di qualificazione
enum colore {viola = 1000};
promozione(viola);
promozione2(true);
float pene = 2.5;
conversioneintera(pene);
conversionebooleana(1);






    return 0;
}
