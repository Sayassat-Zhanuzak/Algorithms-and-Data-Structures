#include <stack>
#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<int> ans(n);
    stack<int> st;

    for (int i = 0; i < n; ++i) {
        int x = a[i];

        while (!st.empty() && st.top() > x) {
            st.pop();
        }

        if (st.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = st.top();
        }
        st.push(x);
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
