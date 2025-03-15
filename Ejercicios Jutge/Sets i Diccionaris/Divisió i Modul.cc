#include <iostream>
#include <set>
using namespace std;

pair<int, int> divmod(int a, int b) {
    pair<int, int> x;
    x.first = a/b;
    x.second = a%b;
    return x;
}

int main() {

    int n, m;
    cin >> n >> m;
    pair<int, int> x = divmod(n, m);
    cout << x.first << " " << x.second << endl;
}