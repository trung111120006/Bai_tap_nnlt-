#include <bits/stdc++.h>

using namespace std;
int count_tong_matrix( vector<vector<int>>&matrix){
    int col = matrix[0].size();
    int row = matrix.size();
    if(col != row)break ; 
    int dem = 0 ; 
    vector<int> check;
    for(int i = 0; i < row; i++){
        int tong = 0;
        for(int j = 0; j < col; j++){
            tong = tong + matrix[i][j]; 
        }
        check.push_back(tong);
        tong =0;
    }
    return dem;
}