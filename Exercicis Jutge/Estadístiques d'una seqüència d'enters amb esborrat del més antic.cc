#include <iostream>
#include <queue>
using namespace std;

void print_queue(queue<int> queue) {
    int min, max, i;
    min = max = i = 0;
    double med = 0.0;
    if (queue.empty()) cout << 0 << endl;
    else {
        while (!queue.empty()) {
            int x = queue.front();
            if (i == 0) {
                min = x;
                max = x;
            } else {
                if (x < min) min = x;
                if (x > max) max = x;
            }
            i++;
            med += x;
            queue.pop();
        }
    
        cout << "min " << min << "; max "<< max << "; media " << double(med*1.0/i) << endl;
    }
}

int main() {

    int n;
    queue<int> qu;
    bool end = false;

    while (not end and cin >> n) {
        if (n > 1000 or n < -1001) {
            end = true;
        } else {
            if (n == -1001) {
                if (!qu.empty()) qu.pop();
            }  else qu.push(n);

            print_queue(qu);

        }
    }
}