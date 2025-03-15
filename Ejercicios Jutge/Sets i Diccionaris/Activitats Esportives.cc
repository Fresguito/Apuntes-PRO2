#include <iostream>
#include <set>
using namespace std;

int main() {

    set<string> x;
    set<string> all;
    set<string> non;
    string z;

    while (cin >> z and z != ".") {
        x.insert(z);
    }

    int n;
    cin >> n;
    all = x;
    non = x;
    set<string>::iterator it;
    for (int i = 0; i < n; i++) {
        set<string> aux;
        while (cin >> z and z != ".") {
            aux.insert(z);
        }

        it = x.begin();
        while (it != x.end()) {
            if (aux.find(*it) == aux.end()) {
                all.erase(*it);
            } else {
                non.erase(*it);  // Asegurarse de que el jugador no esté en "non" si realiza la actividad
            }
            it++;
        }
    }

    cout << "Totes les activitats:";
    for (it = all.begin(); it != all.end(); it++) {
        cout <<" "<< *it;
    }
    cout << endl;

    cout << "Cap activitat:";
    for (it = non.begin(); it != non.end(); it++) {
        cout <<" "<< *it;
    }
    cout << endl;
}

