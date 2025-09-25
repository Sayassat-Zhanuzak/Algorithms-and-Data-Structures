#include <iostream>
#include <algorithm>
using namespace std;

void win(int arr[], int n, int power) {
        int low = 0, high = n - 1;
        int result = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(arr[mid] <= power) {
                result = mid;
                low = mid + 1; 
            } else {
                high = mid - 1;
            }
        }
        int sum = 0;
        for(int i = 0; i <= result; i++) {
            sum += arr[i];
        }
        if(result == -1) {
            sum = 0;
        }

        cout << result + 1 << " " << sum << endl;
    }

int main() {
    int n; 
    cin >> n;
    int comp[n];
    for(int i = 0; i < n; i++) {
        cin >> comp[i];
    }

    int p;
    cin >> p;

    sort(comp, comp + n);

    for(int i = 0; i < p; i++) {
        int power;
        cin >> power;
        win(comp, n, power);
    }

    return 0;

}