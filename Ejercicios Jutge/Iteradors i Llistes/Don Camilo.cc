#include <iostream>
#include <list>
#include <iterator>
using namespace std;

void inserta_don(list<string>& text) {
    list<string>::iterator it = text.begin();

    while (it != text.end()) {
        if (*it == "Camilo") text.insert(it, "Don");
        it++;
    }
}