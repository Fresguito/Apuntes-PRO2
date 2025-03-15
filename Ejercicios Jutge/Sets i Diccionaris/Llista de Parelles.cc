#include <iostream>
#include <map>
#include <list>
using namespace std;

list< pair<string, int> > all_pairs(map<string, int>& M) {
    list<pair<string, int> > f;
    list<pair<string, int> >::iterator it = f.begin();

    map<string, int>:: iterator x = M.begin();
    for (x; x != M.end(); x++) {
        f.insert(it, *x);
    }

    return f;
}

