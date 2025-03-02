#include <iostream>
#include <vector>
using namespace std;

string join(vector<string>::iterator ini, vector<string>::iterator fin, string sep) {
    string word = *ini;
    ini++;
    while (ini != fin) {
        word.append(sep);
        word.append(*ini);
        ini++;
    }
    return word;
}
