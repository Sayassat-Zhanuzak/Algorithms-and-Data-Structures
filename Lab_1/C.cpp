#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    string word_1, word_2;
    cin >> word_1 >> word_2;

    vector<char> first;
    vector<char> second;


    stack<char> letter_1;
    stack<char> letter_2;

    for(int i = 0; i < word_1.size(); i++) {
        if(word_1[i] == '#') {
            letter_1.pop();
        } else{
            letter_1.push(word_1[i]);
        }
    }

    while(!letter_1.empty()){
        first.push_back(letter_1.top());
        letter_1.pop();
    }


    for(int i = 0; i < word_2.size(); i++) {
        if(word_2[i] == '#') {
            letter_2.pop();
        } else{
            letter_2.push(word_2[i]);
        }
    }

    while(!letter_2.empty()){
        second.push_back(letter_2.top());
        letter_2.pop();
    }

    if(second == first) {
        cout << "Yes";
    } else {
        cout << "No";
    }



    return 0;
}