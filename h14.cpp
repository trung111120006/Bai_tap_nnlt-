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
double cofactor_matrix(vector<vector<double>>& matrix, int n){
    vector<vector<double>> cofactor_matrix(n, vector<double>(n));
    vector<vector<double>> submatrix(n - 1, vector<double>(n - 1));
    for (int row = 0; row < n; row++){
        int subrow = 0;
        for (int col = 0; col < n; col++){
            int subcol = 0;
            for (int i = 0; i < n; i++){
                if (i == row) continue;
                for (int j = 0; j < n; j++){
                    if (j == col) continue;
                    submatrix[subrow][subcol] = matrix[i][j];
                    subcol++;
                }
                subrow++;
            }
        }
        cofactor_matrix[row][col] = pow(-1, row + col) * determinant_matrix(submatrix, n - 1);
    }
    return cofactor_matrix;
}
double inverse_matrix(vector<vector<double>>& matrix, int n){
    double det = determinant_matrix(matrix, n);
    if (det == 0){
        cout << "Matrix is singular, cannot find its inverse." << endl;
        return {};
    }
    vector<vector<double>> cofactor = cofactor_matrix(matrix, n);
    vector<vector<double>> adjugate(n, vector<double>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            adjugate[j][i] = cofactor[i][j];
        }
    }
    vector<vector<double>> inverse(n, vector<double>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            inverse[i][j] = adjugate[i][j] / det;
        }
    }
    return inverse;


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
    if (det == 0){
        cout << "Matrix is singular, cannot find its inverse." << endl;
    } else {
        vector<vector<double>> inv = inverse_matrix(matrix, n);
        cout << "Inverse matrix:\n";
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++)
                cout << inv[row][col] << " ";
            cout << endl;
        }
    }
    return 0;
}
