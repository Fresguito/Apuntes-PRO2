#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void push(vector<stack <string> > &Lib, string name, int num) {
    Lib[num-1].push(name);
}

void pop(vector<stack <string> > &Lib, int times, int num) {
    stack<string> x = Lib[num-1];
    int i = 0;
    while (not x.empty() and i < times) {
        x.pop();
        i++;
    }
    Lib[num-1] = x;
}

void print(stack <string> Lib, int n) {
    cout << "Pila de la categoria " << n << endl;
    while (not Lib.empty()) {
        cout << Lib.top() << endl;
        Lib.pop();
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<stack <string> > Lib(n);

    string name;
    int num;

    bool end = false;
    while (not end and cin >> n) {
        if (n == -1) {
            cin >> name >> num;
            push(Lib, name, num);
        } else if (n == -2) {
            int t;
            cin >> t >> num;
            pop(Lib, t, num);
        } else if (n == -3) {
            cin >> num;
            print(Lib[num-1], num);
        } else {
            end = true;
        }
    }
}