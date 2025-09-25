#include <iostream>
using namespace std;

bool bin_search(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    bool result = false;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] == x) {
            result = true;
            break;
        }
        else if(arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

int main() {
    int num;
    cin >> num;
    int arr[num];
    
    for(int i = 0; i < num; i++) {
        cin >> arr[i];
    }

    int target;
    cin >> target;
    
    bool a = bin_search(arr, num, target);
    if(a) cout << "Yes";
    else cout << "No";
    return 0;
}