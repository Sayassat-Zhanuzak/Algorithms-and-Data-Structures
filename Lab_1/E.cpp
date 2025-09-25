#include <iostream>
#include <queue>
using namespace std;


int main() {

    queue<int> boris, nursik;
    for (int i = 0; i < 5; i++) {
        int x; 
        cin >> x;
        boris.push(x);
    }
    for (int i = 0; i < 5; i++) {
        int x; 
        cin >> x;
        nursik.push(x);
    }

    int moves = 0;
    int lim = 1000000;

    while (!boris.empty() && !nursik.empty() && moves < lim) {
        moves++;
        int b = boris.front(); 
        boris.pop();
        int n = nursik.front(); 
        nursik.pop();

        bool borisWins;
        if ((b == 0 && n == 9)) {
            borisWins = true;
        }
        else if ((b == 9 && n == 0)) {
            borisWins = false;
        }
        else {
            borisWins = (b > n);
        }

        if (borisWins) {
            boris.push(b);
            boris.push(n);
        } else {
            nursik.push(b);
            nursik.push(n);
        }
    }

    if (moves >= lim) {
        cout << "blin nichya" << endl;
    } else if (boris.empty()) {
        cout << "Nursik " << moves << endl;
    } else {
        cout << "Boris " << moves << endl;
    }

    return 0;
}