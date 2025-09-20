#include <iostream>
#include <deque>

using namespace std;

    int main() {
    int times;
    cin >> times;
    for(int k = 0; k < times; k++) {
        int size;
        cin >> size;
        deque<int> numbers;

        int arr[size];

        for(int i = 0; i < size; i++) {
            numbers.push_front(i + 1);
        }

        for(int i = 1; i <= size; i++) {
            for(int j = 1; j <= i; j++) {
                int a = numbers.back();
                numbers.push_front(a);
                numbers.pop_back();
            }
            arr[numbers.back() - 1] = i;
            numbers.pop_back();
        }

        for(int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}