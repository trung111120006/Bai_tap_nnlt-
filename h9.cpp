#include <bits/stdc++.h>

using namespace std;

void nhap(int b, int a){
    string s; 
    map < int, char> alphabet;
    if(a>9){
        for (int i =10; i<a; i++){
            alphabet[i] = 'A'+ i -10;
        }
    }
    while (b>0){
        int r = b%a;
        if(r>=10 && a>9){
            s = alphabet[r] +s;
        }else{
            s = to_string(r) +s;
        }
        b = b/a;
    }
    cout<< s;
}
int main (){
    int a,b; 
    cout<< "Input base:";
    cin>>a; 
    cout<< "Input number: ";
    cin>>b;
    nhap(b, a);
}