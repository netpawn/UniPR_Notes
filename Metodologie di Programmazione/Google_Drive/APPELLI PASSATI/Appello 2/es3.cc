//Individuare il problema che si potrebbe presentare nel codice seguente (si noti che si tratta di quattro file sorgente distinti). Fornire un’implementazione alternativa in grado di porvi soluzione.

/************ Inizio file Costante.hh ************/
class Costante {
public:
 static double pi;
 static double e;
// ...
};

/************ Inizio file Costante.cc ************/
#include "Costante.hh"
 Costante::pi = 3.1415;
 Costante::e = 2.72;
// ...

/************ Inizio file Angolo.hh ************/
class Angolo {
public:
 static double piatto;
 static double retto;
 static double giro;
// ...
}; 

/************ Inizio file Angolo.cc ************/
#include "Angolo.hh"
#include "Costante.hh" 
 double Angolo::retto = Costante::pi / 2;
 double Angolo::piatto = Costante::pi;
 double Angolo::giro = Costante::pi * 2;
// ...

//posso violare la ODR se nel codice sorgente includo angolo.hh e costante.hh
//perchè costante.hh è già inclusa nell'implementazione di angolo
//devo inserire nei due header file le guardie



/************ Inizio file Costante.hh ************/
#ifndef GUARDIA_COSTANTE
#define GUARDIA_COSTANTE 1
class Costante {
public:
 static double pi;
 static double e;
// ...
};
#endif //GUARDIA_COSTANTE

/************ Inizio file Angolo.hh ************/
#ifndef GUARDIA_ANGOLO
#define GUARDIA_ANGOLO 1
class Angolo {
public:
 static double piatto;
 static double retto;
 static double giro;
// ...
}; 
#endif //GUARDIA_ANGOLO



