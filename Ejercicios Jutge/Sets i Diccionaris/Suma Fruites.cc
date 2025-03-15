#include <iostream>
#include <map>
using namespace std;

int main() {

    map<string,int> fruites;
    string k;
    int v;
    map<string,int>::const_iterator it;
    while (cin >> k) {
        cin >> v;
        it = fruites.find(k);

        if (it != fruites.end()) fruites[k] += v;
        else fruites[k] = v;
    }

    for (it = fruites.begin(); it != fruites.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}