#include <iostream>
#include <math.h>

using namespace std;
int main (){
    int a,i,b=0; 
    cin>>a; 
    while (a !=0 ){
        i = a%10; 
        b = b*10 + i;
        a = a/10;
    }
    cout<<b;
}