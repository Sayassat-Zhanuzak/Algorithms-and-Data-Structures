#include <iostream>
#include <vector>
using namespace std;

int prefix_function(string s){
    int n = s.size();
    vector<int> pi(n);
    pi[0] = 0;
    int c = 0;
    for(int i = 1; i < n; i++){
        int j = pi[i - 1];
        while(j > 0 && s[i] != s[j]){
            j = pi[j - 1];
        }
        if(s[i] == s[j]){
            j++;
        }
        pi[i] = j;
    }
    return pi[n-1];
}


int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        int t;
        cin >> s >> t;
        int s_s = s.size();
        s_s *= t;
        int c = prefix_function(s);
        s_s = s_s - (c * (t - 1));
        cout << s_s << endl;
    }
}
