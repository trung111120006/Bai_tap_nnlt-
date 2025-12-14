#include <bits/stdc++.h>

using namespace std;
int main (){
    int x = 5; 
    string s = "1";
    int *p;
    int *k;
    int *n = &x;
    *p = x;
    k = &x;
    if(!s.empty()){
        cout << "chuoi ko rong";
    }
    cout << *p;
    return 0;
}