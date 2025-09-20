#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    string word;
    cin >> word;

    stack<char> letter;

    for(int i = 0; i < word.size(); i++) {
        if(word[i] == 's') {
            continue;
        } else {
            if(letter.empty()) {
                letter.push(word[i]);
            } else {
                if(word[i] == letter.top()) {
                    letter.pop();
                } else {
                    letter.push(word[i]);
                }
            }
        }
    }

    if(!letter.empty()) {
        cout << "NO";
    } else {
        cout << "YES";
    }
}