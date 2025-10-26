#include <bits/stdc++.h>

using namespace std;
void Fibonacci(int n){
    int a=0, b=1, c;
    if(n==0) {
        cout << a << endl;
        return;
    }
    if(n==1) {
        cout << b << endl;
        return;
    }  
    for(int i=2; i<n; i++){
        c = a + b;
        a = b;
        b = c;
    }
    cout << c << endl;
}
int main() {
    int  n;
    cin >> n;
    Fibonacci(n);
}