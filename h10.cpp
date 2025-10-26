#include <bits/stdc++.h>

using namespace std; 
void determinant(int n, int matrix[n][n]){
    if(n==1){
        return matrix[0][0];
    }
    if(n==2){
        return matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0];
    }
    int det =0;
    for(int p=0; p<n; p++){
        int submatrix[n-1][n-1];
        for(int i=1; i<n; i++){
            int colIndex =0;
            for(int j=0; j<n; j++){
                if(j==p) continue;
                submatrix[i-1][colIndex] = matrix[i][j];
                colIndex++;
            }
        }
        det += matrix[0][p] * pow(-1, p) * determinant(n-1, submatrix);
    }
    return det;
}
int main (){
    int n;
    cout<< "Input maxtri nxn: ";
    cin >> n;
    int maxtrix[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> maxtrix[i][j];
        }
    }
    cout << "Determinant: " << determinant(n, maxtrix) << endl;
    return 0;
}