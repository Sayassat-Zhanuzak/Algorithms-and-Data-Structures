#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<char> a;

    string brackets;
    cin >> brackets;

    a.push(brackets[0]);
    if(brackets[0] == ')' || brackets[0] == ']' || brackets[0] == '}') {
        cout << "NO";
        return 0;
    }

    for(int i = 1; i < brackets.size(); i++) {
        if((brackets[i] == ')' && !a.empty() && a.top() == '(') || (brackets[i] == ']' && !a.empty() && a.top() == '[') || (brackets[i] == '}' && !a.empty() && a.top() == '{')) {
            a.pop();
        } else {
            a.push(brackets[i]);
        }
    }

    if(a.empty()) { 
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}