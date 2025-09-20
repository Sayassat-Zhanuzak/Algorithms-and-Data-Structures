#include <iostream>
// #include <stack>
#include <vector>

using namespace std;

bool is_it_prime(int a) {
    if(a == 1 || a == 0) return false;
    for(int i = 2; i < a; i++) {
        if(a % i == 0) return false;
    }
    return true;
}

int main() {
    int limit = 100000;
    
    int n; cin >> n;

    vector<bool> is_prime(limit + 1, true);
    vector<int> primes;

    // stack<int> superprimes;
    vector<int> superprimes;

    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i * i <= limit; i++) {
        if(is_prime[i]) {
            for(int j = i * i; j <= limit; j += i) {
                is_prime[j] = false;
            }
        }
    }

    for(int i = 2; i <= limit; i++) {
        if(is_prime[i]) {
            primes.push_back(i);
        }
    }

    for(int i = 0; i < primes.size(); i++) {
        if(is_it_prime(i)) {
            superprimes.push_back(primes[i - 1]);
            if(superprimes.size() == n) {
                cout << superprimes[n - 1] << endl;
                return 0;
            }

        }
    }
}