#include <iostream>
#include <vector>
using namespace std;

vector<string>::const_iterator longest(const vector<string>& v) {
    if (v.empty()) return v.end();
    
    vector<string>::const_iterator it = v.begin();
    vector<string>::const_iterator final;
    string larg = "";
    while (it != v.end()) {
        if (it == v.begin()) {
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