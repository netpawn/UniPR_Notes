//
//  main.cpp
//  costruttori
//
//  Created by Tommaso Pellegrini on 07/09/2020.
//  Copyright © 2020 Tommaso Pellegrini. All rights reserved.
//

#include <iostream>
using namespace std;


class classe{
    int i;
public:
    
   // classe();  //costruttore semplice
    classe(){  //costruttore parametreizzato
        int i=0;
    }
    classe(const classe &t){//costruttore di copia
        i = t.i;
    }
    ~classe(); //distruttore
    
};




int main(int argc, const char * argv[]) {
    cout << "Begin testing" << endl;
    
    
    
    
    
    
    
    
    
    
    cout << "End testing" << endl;
    return 0;
}
