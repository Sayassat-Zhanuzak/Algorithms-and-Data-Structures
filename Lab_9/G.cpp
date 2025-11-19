#include <iostream>
#include <vector>
using namespace std;

void prefix_function(string s) {
    int n = s.size();
    vector<int> pi(n);
    pi[0] = 0;
    int c = 0;
    int m = 0;
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) 
            j = pi[j - 1];
        if(s[i] == s[j])
            j++;
        pi[i] = j;
    }
    cout << n - pi[n - 1];
}

int main(){
    string s;
    cin >> s;
    prefix_function(s);
}