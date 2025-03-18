#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

struct info {
    set <string> paths;
    vector <int> times;
};

typedef map<string, info> custom_map;

/*
PRE: Cierto
POST: 
    - CIERTO: Se encuentra una subsecuencia de 20 "times" que cumplen que [time(a+1) - time(a) < 100]
    - FALSO: El tamaño del vector de "times" no supera las 20 unidades
*/
bool scraper_boot_found(const vector<int> &info) {
    if (info.empty() or info.size() < 20) return false;

    int cons = 1; // Usamos esta variable auxiliar para contar las unidades de tiempo que cumplen la condición
    for (int i = 1; i < info.size(); i++) {
        if (info[i] - info[i - 1] < 100) {
            cons++;
            if (cons == 20) return true; // Si exactamente hay 20, hemos encontrado una subsecuencia valida
        } else {
            cons = 1; // Si no se cumple la condición, se vuelve a contar de nuevo
        }
    }

    return false;
}

/*
PRE: Cierto
POST: Se observa en el canal de salida la "ip" del scraper bot seguida de los "paths"
*/
void print_scraper_boot(const string &ip, const set<string> &s, set<string>::const_iterator & it_set) {

    cout << ip ;
    for (it_set= s.begin(); it_set != s.end(); it_set++) {
        cout << " " << *it_set;
    }
    cout << endl;
}

/*
PRE: Cierto
POST: ip_map pasa a ser un "custom_map" con los valores de entrada insertados
*/
void read_map(custom_map &ip_map) {

    string ip, path;
    int time;
    
    while (cin >> ip) {
        cin >> path >> time;
        ip_map[ip];
        ip_map[ip].paths.insert(path);
        ip_map[ip].times.push_back(time);
    }
    
}

int main() {

    custom_map ip_map;
    custom_map::const_iterator it_map;
    set<string>::const_iterator it_set;

    read_map(ip_map);
    
    bool no_bots = false;
    for (it_map = ip_map.begin(); it_map != ip_map.end(); it_map++) {
        if (scraper_boot_found(it_map->second.times)) {
            no_bots = true;
            print_scraper_boot(it_map->first, it_map->second.paths, it_set);
        }
    }
    if (not no_bots) cout << "No bots" << endl;

}

