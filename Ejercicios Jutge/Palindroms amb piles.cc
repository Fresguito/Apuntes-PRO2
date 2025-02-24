#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    vector<int> sequence;
    int n, j;
    cin >> j;
    int half = j / 2;
    if (j % 2 != 0) half++;

    stack<int> palind;
    for (int i = 0; i < half; i++) {
        cin >> n;
        palind.push(n);
    }

    bool simetric = true;
    if (j % 2 != 0) palind.pop();
    while (simetric and not palind.empty() and half < j) {
        cin >> n;
        if (n != palind.top()) {
            simetric = false;
        }
        palind.pop();
        half++;
    }

    if (simetric) cout << "SI" << endl;
    else cout << "NO" << endl;
}