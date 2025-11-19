#include <iostream>
#include <vector>

using namespace std;

vector<int> prefix_function(string s) {
    int n = s.size();
    vector<int> pi(n);
    pi[0] = 0;
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

void KMP(string text, string pattern) {
    string s = pattern + '#' + text + text;
    int n = s.size();
    int m = pattern.size();
    bool is_cycle = true;
    int pos;
    vector<int> pi = prefix_function(s);
    for (int i = m + 1; i < n; i++) {
        if(pi[i] == m) {
            pos = i - m - m;
            is_cycle = true;
            break;
        } else {
            is_cycle = false;
        }
    }
    if(is_cycle)
        cout << pos;
    else 
        cout << "-1";
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    KMP(s2, s1);
    return 0;
}