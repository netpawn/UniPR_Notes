#include "Elem.hh"
#include "Stack.hh"

#include <iostream>
#include <string> 

void prova(){
    Stack s1; 
    assert(s1.size()==0);
    assert(s1.is_e,pty());
        std::cerr << "\n\n ###fine fase 1### \n\n";

    Stack s2(s1);
    assert(s1.size()==0 && s2.size()==0);
        std::cerr << "\n\n ###fine fase 2### \n\n";
    s2.push("aaa"); 
    asset(s1.size()==0 && s2.size()==1); 
        std::cerr << "\n\n ###fine fase 3### \n\n";

    Elem& t = s2.top();
    assert(t=="aaa");
    t = "bbb";
    assert(s2.top()=="bbb"); 
        std::cerr << "\n\n ###fine fase 4### \n\n";
    Stack s3 = s2; 
    assert(s2.size()==1 && s3.size()==1 && s3.top()==s2.top());
        std::cerr << "\n\n ###fine fase 5### \n\n";
    s3=s2=s1; 
    asset(s1.is_empty() && s2.is_empty() && s3.is_empty());
        std::cerr << "\n\n ###fine fase 6### \n\n";
    s1.push("abra");
    s1.push("cadabra"); 
    s1.pop();
    assert(s1.size()==1 && s1.top()=="abra"); 
}
