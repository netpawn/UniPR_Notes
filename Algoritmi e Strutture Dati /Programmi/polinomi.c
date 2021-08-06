#include <stdio.h>
#include <math.h>

const int D_MAX = 100;

typedef struct {
    double coefficienti[D_MAX];
    int d;
} polinomio;

void stampaPolinomio(polinomio p) {
    
    for (int i = p.d; i > 0; i--)
        printf("%lf %s %d %s",p.coefficienti[i], "x^", i, " + ");
    printf("%lf \n", p.coefficienti[0]);
    
    return;
}

polinomio calcolaSomma(polinomio p1, polinomio p2) {
    polinomio s;
    
    int dmax;
    
    if(p1.d > p2.d)
        dmax = p1.d;
    else
        dmax = p2.d;
    
    s.d = dmax;
    
    for (int i = 0; i <= dmax; i++)
        s.coefficienti[i] = p1.coefficienti[i] + p2.coefficienti[i];
    
    return s;
}

polinomio calcolaProdotto(polinomio p1, polinomio p2) {
    polinomio p;
    
    p.d = p1.d + p2.d;
    
    for (int k = 0; k <= p.d; k++)
        p.coefficienti[k] = 0;
    
    if (p.d > D_MAX) {
        printf("Il grado è troppo grande! \n");
        return p;
    }
    
    for (int i = 0; i <= p1.d ; i++)
        for (int j = 0; j <= p2.d ; j++)
            p.coefficienti[i+j] += p1.coefficienti[i] * p2.coefficienti[j];
    
    return p;
}

polinomio calcolaDerivata(polinomio p) {
    polinomio pd;
    
    pd.d = p.d - 1;
    
    for (int i = 0; i < p.d; i++)
        pd.coefficienti[i] = (i+1) * p.coefficienti[i+1];
    
    return pd;
}

double valutaPolinomio(polinomio p, double x) {
    double s = p.coefficienti[0];
    
    for (int i = 1; i <= p.d; i++)
        s = s + p.coefficienti[i] * pow(x,i);
    
    return s;
}

int main() {
    polinomio p1;
    polinomio p2;
    polinomio s;
    polinomio p;
    polinomio pd;
    double x, y;
    
    for (int k = 0; k < D_MAX; k++) {
        p1.coefficienti[k] = 0;
        p2.coefficienti[k] = 0;
    }
    
    //p1(x) = x^3 - 7x + 6
    p1.d = 3;
    p1.coefficienti[0] = 6;
    p1.coefficienti[1] = -7;
    p1.coefficienti[2] = 0;
    p1.coefficienti[3]= 1;
    
    //p2(x) = x^2 - 1
    p2.d = 2;
    p2.coefficienti[0] = -1;
    p2.coefficienti[1] = 0;
    p2.coefficienti[2] = 1;
    
    printf("%s\n", "Polinomio p1: ");
    stampaPolinomio(p1);
    printf("%s\n", "Polinomio p2: ");
    stampaPolinomio(p2);
    
    
    // calcolo p1(x) + p2(x)
    s = calcolaSomma(p1, p2);
    printf("%s\n", "Polinomio Somma: ");
    stampaPolinomio(s);
    
    // calcolo p1(x) * p2(x)
    p = calcolaProdotto(p1, p2);
    printf("%s\n", "Polinomio Prodotto: ");
    stampaPolinomio(p);
    
    // calcolo p1'(x)
    pd = calcolaDerivata(p1);
    printf("%s\n", "Polinomio Derivato: ");
    stampaPolinomio(pd);
    
    // calcolo p1(x)
    x = 1.0;
    y = valutaPolinomio(p1, x);
    printf("%s %lf %s %lf\n", "Il polinomio calcolato in ", x, " vale: ", y);
    
    return 0;
}