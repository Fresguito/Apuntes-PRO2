#include <iostream>

using namespace std;

#include "BinTree.hh"

// Pre:
// Post: Retorna el nombre de fulles de t
int numberOfLeaves(BinTree<int> t) {
    if (t.empty()) return 0;
    int is = 0;
    int l = numberOfLeaves(t.left());
    int r = numberOfLeaves(t.right());
    if (l == 0 and r == 0) is = 1;
    is += (l+r);
    return is;
}