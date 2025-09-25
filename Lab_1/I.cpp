#include <iostream>
#include <queue>
using namespace std;

int main() {

    int n;
    cin >> n;

    string s;
    cin >> s;

    queue<int> qS, qK;

    for (int i = 0; i < n; ++i) {
        if (s[i] == 'S') {
            qS.push(i);
        }
        else {
            qK.push(i);
        }
    }

    while (!qS.empty() && !qK.empty()) {
        int i = qS.front(); 
        qS.pop();

        int j = qK.front(); 
        qK.pop();

        if (i < j) {
            qS.push(i + n);
        } else {
            qK.push(j + n);
        }
    }

    if (qS.empty()) {
        cout << "KATSURAGI" << endl;
    } else {
        cout << "SAKAYANAGI" << endl;
    }

    return 0;
}