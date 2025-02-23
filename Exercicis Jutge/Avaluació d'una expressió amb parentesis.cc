#include <iostream>
#include <stack>
using namespace std;

bool pareja(char top, char bottom) {
    return (top == '(' and bottom == ')') or (top == '[' and bottom == ']');
}

int main() {

    stack<pair<char, int> > pila;
    int pos = 0;
    char c;
    bool found = false;

    while (not found and cin >> c and c != '.') {
        pos++;
        if (c == '(' or c == '[') {
            pila.push({c, pos});
        } else {
            if (pila.empty() or not pareja(pila.top().first, c)) {
                found = true;
            } else pila.pop();
        }
    }

    if (not pila.empty() or found) cout << "Incorrecte " << pos << endl;
    else cout << "Correcte" << endl;

}