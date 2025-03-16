#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> freq;
    map<string, int>::iterator it;

    char i;
    string name;
    while (cin >> i) {
        cin >> name;
        if (i == 'a') {
            it = freq.find(name);
            if (it != freq.end()) freq[name] += 1;
            else freq[name] = 1;
        } else if (i == 'f') {
            it = freq.find(name);
            if (it != freq.end()) cout << it->second << endl;
            else cout << 0 << endl;
        }
    }
}

