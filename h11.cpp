//Bài tập tính det ma trận vuông bất kỳ 
//bài tập tính phần tử nhỏ nhất trong ma trận đa chiều 
#include <bits/stdc++.h>
using namespace std;

void Min_number_maxtri(int maxtrix[], int n) {
    int temp = maxtrix[0];
    for (int i = 1; i < n; i++) {
        if (maxtrix[i] < temp) {
            temp = maxtrix[i];
        }
    }
    cout << temp << endl;
}

int main() {
    int n;
    cin >> n;
    int maxtrix[n];
    for (int i = 0; i < n; i++) {
        cin >> maxtrix[i];
    }
    Min_number_maxtri(maxtrix, n);
    return 0;
}
