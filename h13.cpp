//Bài tập tính det ma trận vuông bất kỳ 

#include <bits/stdc++.h>

using namespace std;
int determinant_matrix(vector<vector<int>>& matrix, int row, int col) {
    if( row != col ){
        cout << "indefinite determinant" << endl;
        return 0;
    }
    if(row == 1){
        return matrix[0][0];
    }
    if(row == 2){
        return (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]);
    }
    int det = 0;
    for(int p = 0; p < col; p++){
        vector<vector <int>> submatrix (row -1, vector <int> (col -1));
        for(int i = 1; i < row; i++){
            int sub_col = 0;
            for(int j=0 ; j < col; j++){
                if(j == p){
                    continue;
                }
                submatrix[i -1][sub_col] = matrix[i][j];
                sub_col++;
            }
        }
        det = det + matrix[0][p] * pow(-1, 0 + p) * determinant_matrix(submatrix, row -1, col -1);
    }
    return det;
}

int main (){
    int row, col; 
    cout << "Enter number of rows: "; 
    cin >> row;
    cout << "Enter number of columns: ";
    cin >> col;
    vector<vector <int>> matrix ( row , vector<int> (col)); //Input matrix include row and each row include col elements
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cin >> matrix[i][j];
        }
    }
    determinant_matrix(matrix, row, col);
    cout << "Determinant of the matrix is: " << determinant_matrix(matrix, row, col) << endl;
    return 0;
}
