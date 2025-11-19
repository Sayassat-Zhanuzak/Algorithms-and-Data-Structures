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

void KMP(string text, string pattern, int num) {
    string s = pattern + '#' + text;
    int n = s.size();
    int m = pattern.size();
    int cnt = 0;

    vector<int> pi = prefix_function(s);

    for(int i = m + 1; i < n; i++) {
        if (pi[i] == m)
            cnt++;
    }

    if (num <= cnt)   
        cout << "YES";
    else 
        cout << "NO";   
}

int main() {
    string pattern, text;
    int num;
    cin >> pattern >> num >> text;
    KMP(text, pattern, num);
    return 0;
}