#include <iostream>
#include <math.h> 

using namespace std;
int main (){
    int a,b; 
    cin>>a>>b; 
    if(a<b){
        for(int i=a; i<=b;i++){
            if((i%4==0 && i%100!=0) || (i%400==0)){
                cout<<i<<endl; 
            }
        }
    }else {
        for(int i=b; i<=a;i++){
            if((i%4==0 && i%100!=0) || (i%400==0)){
                cout<<i<<endl; 
            }
        }
    }
    return 0;
}