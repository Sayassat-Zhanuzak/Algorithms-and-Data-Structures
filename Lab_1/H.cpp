#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> num;
    if(n <= 1) {
        cout << "NO";
        return 0;
    }

    for(int i = 2; i <= n; i++) {
        if(n % i == 0) {
            num.push_back(i);
            if(num.size() >= 2) {
                cout << "NO";
                return 0;
        }
    }
}

    if(num.size() == 1) {
        cout << "YES";
    }

}