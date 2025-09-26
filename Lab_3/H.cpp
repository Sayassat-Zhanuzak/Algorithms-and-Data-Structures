#include <iostream>
using namespace std;

int binary_search(int arr[], int n, int x){
    int low = 0, high = n;
    while(low < high) {
        int mid = low + (high - low)/2;
        if(arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

int main() {
    int block_num, mistake_num;
    cin >> block_num >> mistake_num;

    int lines[block_num];

    for(int i = 0; i < block_num; i++) {
        cin >> lines[i];
    }

    int p[block_num];
    int sum = 0;


    for(int i = 0; i < block_num; i++) {
        sum += lines[i];
        p[i] = sum;
    }

    for(int i = 0; i < mistake_num; i++) {
        int mistake;
        cin >> mistake;
        int a = binary_search(p, block_num, mistake);
        cout << a + 1 << endl;
    }

    return 0;

}