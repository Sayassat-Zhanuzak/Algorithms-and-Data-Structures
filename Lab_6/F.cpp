#include <iostream>
#include <vector>
#include <iomanip>
#include <utility>
#include <string>

using namespace std;

bool less_student(pair<pair<string, string>, double> &a, pair<pair<string, string>, double> &b) {
    if (a.second != b.second) return a.second < b.second;
    if (a.first.first != b.first.first) return a.first.first < b.first.first;
    return a.first.second < b.first.second;
}

void quick_sort(vector<pair<pair<string, string>, double>> &v, int left, int right) {
    int i = left;
    int j = right;

    auto p = v[(left + right) / 2];

    while (i <= j) {
        while (less_student(v[i], p)) i++;
        while (less_student(p, v[j])) j--;

        if(i <= j) {
            swap(v[i], v[j]);
            i++;
            j--;
        }
    }

    if (left < j) quick_sort(v, left, j);
    if (i < right) quick_sort(v, i, right);
}

int main() {
    int n;
    cin >> n;

    string name, surname;
    vector<pair<pair<string, string>, double> > student;
    
    for(int i = 0; i < n; i++) {
        double gpa = 0;
        int overall = 0;
        cin >> surname >> name;
        int k; cin >> k;
        for(int j = 0; j < k; j++) {
            string mark;
            cin >> mark;
            int mark_count;
            cin >> mark_count;
            overall += mark_count;
            if (mark == "A") 
                gpa += mark_count * 3.75;
            else if (mark == "A+") 
                gpa += mark_count * 4.00;
            else if(mark == "B+")
                gpa += mark_count * 3.50;
            else if(mark == "B")
                gpa += mark_count * 3.00;
            else if(mark == "C+")
                gpa += mark_count * 2.50;
            else if(mark == "C")
                gpa += mark_count * 2.00;
            else if(mark == "D+")
                gpa += mark_count * 1.50;
            else if(mark == "D")
                gpa += mark_count * 1.00;
            else
                gpa += mark_count * 0.00;
        }
        gpa = gpa / overall;
        student.push_back(make_pair(make_pair(surname, name), gpa));
    }

    quick_sort(student, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << fixed << setprecision(3) << student[i].first.first << " " << student[i].first.second << " " << student[i].second << endl;
    }
    return 0;
}