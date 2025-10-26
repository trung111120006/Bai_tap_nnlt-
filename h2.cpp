#include <iostream>
#include <math.h> 

using namespace std;
void SoNguyenTO (int n){
    for(int i=2; i<n;i++){
        int dem =0; 
        for(int j=1; j<=i;j++){
            if(i%j==0){
                dem++; 
            }
        }
        if(dem==2){
            cout<<i<<endl; 
        }
    }
}
int main (){
    int a; 
    cin >>a;
    SoNguyenTO(a);
    return 0;
}
