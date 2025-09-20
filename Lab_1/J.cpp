#include <iostream>
#include <vector>
#include <deque>
#include <string>

using namespace std;

int main() {

    deque<int> numbers;
    vector<string> simvol;
    string a;
    while(a != "!") {
        cin >> a;
        simvol.push_back(a);
    }

    for(int i = 0; i < simvol.size(); i++) {
        if(simvol[i] == "+") {
            numbers.push_front(stoi(simvol[i + 1]));
        }
        if(simvol[i] == "-") {
            numbers.push_back(stoi(simvol[i + 1]));
        }
        if(simvol[i] == "*") {
            if(!numbers.empty()) {
                cout << numbers.back() + numbers.front() << endl;
                numbers.pop_front();
                if(!numbers.empty()) {
                    numbers.pop_back();
                }
            } else {
                cout << "error" << endl;
            }
        }
    }
}