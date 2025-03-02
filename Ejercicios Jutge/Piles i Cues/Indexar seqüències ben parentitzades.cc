#include <iostream>
#include <stack>
using namespace std;

int main() {
    string line;
    stack<int> pos;
    while (getline(cin, line)) {
        int counter = 1;
        for (int i = 0; i < line.size(); i++) {
            char c = line[i];
            if (c == '(') {
                pos.push(counter);
                cout << c << counter;
                counter++;
            } else {
                cout << c << pos.top();
                pos.pop();
            }
        }
        cout << endl;
    }
}