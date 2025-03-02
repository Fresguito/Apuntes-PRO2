#include <iostream>
#include <list>
using namespace std;

list<string>::const_iterator longest(const list<string>& L) {
    if (L.empty()) return L.end();
    
    list<string>::const_iterator it = L.begin();
    list<string>::const_iterator final;
    string larg = "";
    while (it != L.end()) {
        if (it == L.begin()) {
            larg = *it;
            final = it;
        } else {
            string aux = *it;
            if (aux.size() > larg.size()) {
                larg = aux;
                final = it;
            }
        }
        it++;
    }
    return final;
}
