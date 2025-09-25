#include <iostream>
#include <cmath>
using namespace std;

bool possible(int arr[], int bag, int hours, int steal) {
    int sum = 0;
    for(int i = 0; i < bag; i++) {
        int a = ceil(double(arr[i])/double(steal));
        sum += a;
    }
    return sum <= hours;
}

int main() {
    int bag, hours;
    cin >> bag >> hours;
    int gold[bag];

    for(int i = 0; i < bag; i++) {
        cin >> gold[i];
    }

    int max = gold[0];
    for(int i = 0; i < bag; i++) {
        if(max < gold[i]) max = gold[i];
    }

    int low = 1, high = max;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(possible(gold, bag, hours, mid)) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << low << endl;
    return 0;
}