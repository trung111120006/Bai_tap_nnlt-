//Bài tập tính det ma trận vuông bất kỳ 

#include <bits/stdc++.h>

using namespace std;
void det_matrix(int matrix[][], int n){
    int det = 0; 
    if(n==0){
        cout<< "0";
    }else if(n==1){
        cout << matrix[0][0];
    }else if(n==2){
        det = matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0];
        cout << det;
    }
}
int main(){
    int n;
    cin >> n;
    int matrix[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    
    return 0;
}
