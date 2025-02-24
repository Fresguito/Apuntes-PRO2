#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void read_queue(vector < queue<string> > &Super, int pos) {
    string line;
    getline(cin, line);

    if (!line.empty()) {
        string word = "";
        for (int i = 0; i < line.size(); i++) {
            if (line[i] ==' ') {
                if (!word.empty()) {
                    Super[pos].push(word);
                    word = "";
                }
            } else {
                word.push_back(line[i]);
            }
        }

        if (!word.empty()) {
            Super[pos].push(word);
        }
    }
}

int main() {
    int n;
    cin >> n;
    cin.ignore();

    vector < queue<string> > Super(n);
    vector <string> departs;

    for (int i = 0; i < n; i++) {
        read_queue(Super, i);
    }
    
    string act;
    int qu;
    while (cin >> act) {
        if (act == "LEAVES") {
            cin >> qu;
            if (qu >= 1 and qu <= n and !Super[qu-1].empty()) {
                string aux = Super[qu-1].front();
                departs.push_back(aux);
                Super[qu-1].pop();
            }
        } else if (act == "ENTERS") {
            string name;
            cin >> name >> qu;
            if (qu >= 1 and qu <= n) Super[qu-1].push(name);
        }
    }

    cout << "DEPARTS" << endl << "-------" << endl;

    for (int i = 0; i < departs.size(); i++) {
        cout << departs[i] << endl;
    }
    cout << endl;

    cout << "FINAL CONTENTS" << endl << "--------------" << endl;
    for (int i = 0; i < n; i++) {
        
        cout << "queue " << i+1 << ":";
        while (not Super[i].empty()) {
            cout << " " << Super[i].front();
            Super[i].pop();
        }
        cout << endl;
    }
}