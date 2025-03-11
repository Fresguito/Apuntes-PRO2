#include <iostream>
#include <map>
using namespace std;

int main() {

    map<string, string> dic;
    string k, v, ent;
    bool final = false;
    while (not final and getline(cin, ent)) {
        if (not ent.empty()) {
            int spacePos = ent.find(' ');
            k = ent.substr(0, spacePos);
            v = ent.substr(spacePos+1);
            dic.insert(make_pair(k,v));
        } else final = true;
    }

    while (cin >> k) {
        map<string, string>::const_iterator it;
        it = dic.find(k);
        if (it == dic.end()) cout << "<not found>" << endl;
        else cout << it->second << endl;
    }
}
