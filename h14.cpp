//Bài tập tính det và nghịch đảo ma trận vuông bất kỳ
#include <bits/stdc++.h>
using namespace std;

double determinant_matrix(vector<vector<double>>& matrix, int n) {
    if (n == 1) return matrix[0][0];
    if (n == 2) return matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0];

    double det = 0;
    vector<vector<double>> submatrix(n - 1, vector<double>(n - 1));
    for (int p = 0; p < n; p++) {
        int subi = 0;
        for (int i = 1; i < n; i++) {
            int subj = 0;
            for (int j = 0; j < n; j++) {
                if (j == p) continue;
                submatrix[subi][subj] = matrix[i][j];
                subj++;
            }
            subi++;
        }
        det += pow(-1, p) * matrix[0][p] * determinant_matrix(submatrix, n - 1);
    }
    return det;
}

vector<vector<double>> inverse_matrix(vector<vector<double>>& matrix, int n) {
    double det = determinant_matrix(matrix, n);
    if (det == 0) {
        cout << "Matrix is singular and cannot be inverted." << endl;
        return {};
    }

    vector<vector<double>> adj(n, vector<double>(n));
    vector<vector<double>> submatrix(n - 1, vector<double>(n - 1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int subi = 0;
            for (int x = 0; x < n; x++) {
                if (x == i) continue;
                int subj = 0;
                for (int y = 0; y < n; y++) {
                    if (y == j) continue;
                    submatrix[subi][subj] = matrix[x][y];
                    subj++;
                }
                subi++;
            }
            adj[j][i] = pow(-1, i + j) * determinant_matrix(submatrix, n - 1) / det; // chuyển vị
        }
    }

    return adj;
}

int main() {
    int n;
    cout << "Enter size of square matrix: ";
    cin >> n;

    vector<vector<double>> matrix(n, vector<double>(n));
    cout << "Enter matrix elements:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];

    double det = determinant_matrix(matrix, n);
    cout << "Determinant = " << det << endl;

    vector<vector<double>> inv = inverse_matrix(matrix, n);
    if (!inv.empty()) {
        cout << "Inverse matrix:\n";
        for (auto& row : inv) {
            for (double val : row)
                cout << fixed << setprecision(3) << val << " ";
            cout << endl;
        }
    }
    return 0;
}
