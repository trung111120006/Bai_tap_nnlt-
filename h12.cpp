// Bài tính tích 2 ma trận mn và np
#include <bits/stdc++.h>
using namespace std;

void multiplyMatrix(const vector<vector<int>>& matrixA, const vector<vector<int>>& matrixB, vector<vector<int>>& resultMatrix, int m, int n, int p) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            resultMatrix[i][j] = 0;
            for (int k = 0; k < n; k++) {
                resultMatrix[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    cout << "Resultant Matrix after multiplication:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            cout << resultMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int m, n, p;
    cout << "Enter number of rows and columns of first matrix: ";
    cin >> m >> n;
    cout << "Enter number of columns of second matrix: ";
    cin >> p;

    vector<vector<int>> matrixA(m, vector<int>(n));
    vector<vector<int>> matrixB(n, vector<int>(p));
    vector<vector<int>> resultMatrix(m, vector<int>(p, 0));

    cout << "Enter elements of first matrix:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrixA[i][j];
        }
    }

    cout << "Enter elements of second matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            cin >> matrixB[i][j];
        }
    }
    multiplyMatrix(matrixA, matrixB, resultMatrix, m, n, p);
    return 0;
}