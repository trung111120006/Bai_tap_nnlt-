//bài tập tính phần tử nhỏ nhất trong ma trận đa chiều 
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> kichthuoc(n);
    long long total_size = 1;

    // Nhập kích thước từng chiều và tính tổng số phần tử
    for (int i = 0; i < n; i++) {
        cin >> kichthuoc[i];
        total_size *= kichthuoc[i];
    }

    vector<int> a(total_size);
    int min_val, max_val;

    for (long long i = 0; i < total_size; i++) {
        cin >> a[i];
        if (i == 0) {
            min_val = max_val = a[i];
        } else {
            if (a[i] < min_val) min_val = a[i];
            if (a[i] > max_val) max_val = a[i];
        }
    }

    cout << "Min = " << min_val << endl;
    cout << "Max = " << max_val << endl;

    return 0;
}
