#include <iostream>
#include <map>
using namespace std;

char min_to_maj(char c) {
    if (c >= 'a' and c <= 'z') {
        c -= 'a';
        c += 'A';
    }
    return c;
}

string to_morse(string s, const map<char,string>& M) {
    string word;
    for (int i = 0; i < s.size(); i++) {
        char x = min_to_maj(s[i]);
        map<char,string>::const_iterator it;
        it = M.find(x);
        if (it != M.end()) {
            if (i != 0) word.append(" ");
            word.append(it->second);
        }
    }
    return word;
}