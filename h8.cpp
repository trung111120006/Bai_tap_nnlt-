#include <bits/stdc++.h>

using namespace std;
int main (){
    int n, dem=0; 
    cin>>n;
    for(int i=2; i<= n; i++){
        for(int j=1; j<i ; j++){
            if(i%j==0) dem++;
        }
        if(dem == 1) cout<<i<<endl;
        dem=0;
    }
    return 0;

}