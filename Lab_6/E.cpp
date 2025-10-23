#include <iostream>
#include <vector>  
#include <utility>
using namespace std;

void quick_sort(vector<int> &v, int left, int right) {
    int i = left;
    int j = right;
    int p = v[(right + left) / 2];

    while(i <= j) {
        while (v[i] > p) i++;
        while (p > v[j]) j--;
        if(i <= j) {
            swap(v[i], v[j]);
            i++;
            j--;
        }
    }

    if(left < j) quick_sort(v, left, j);
    if (i < right) quick_sort(v, i, right);
}

int main(){

    int n, m;
    cin >> n >> m;

    int arr[n][m];

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    vector<int> col;

    for (int j = 0; j < m; j++) {
        col.clear();
        for (int i = 0; i < n; i++) {
            col.push_back(arr[i][j]);
        }

        quick_sort(col, 0, n - 1);

        for (int i = 0; i < n; i++)
            arr[i][j] = col[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}