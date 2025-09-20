#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int order, limit;
    limit = 1000000;
    cin >> order;
    

    vector<bool> is_prime(limit + 1, true);
    stack<int> primes;

    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i * i <= limit; i++) {
        if(is_prime[i]) {
            for(int j = i * i; j <= limit; j+=i) {
                is_prime[j] = false;
            }
        }
    }

    for(int i = 0; i <= limit; i++) {
        if(is_prime[i]) {
            primes.push(i);
            if(primes.size() == order) {
                cout << primes.top();
                return 0;
            }
        }
    }




    return 0;
}