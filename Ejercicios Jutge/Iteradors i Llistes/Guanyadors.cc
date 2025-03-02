#include <iostream>
#include <vector>
using namespace std;

struct Player { 
    string name; 
    int score;
};

vector<string> winners(vector<Player>::iterator ini, vector<Player>::iterator fin) {
    vector<string> win;
    if (ini == fin) return win;
    int max = ini->score;

    while (ini != fin) {
        if (ini->score >= max) {
            if (ini->score > max) win.clear();
            max = ini->score;
            win.push_back(ini->name);
        }
        ini++;
    }

    return win;
}