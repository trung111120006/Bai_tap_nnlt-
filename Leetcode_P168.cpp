#include <bits/stdc++.h>

using namespace std;

string trung(int s){
    map<int, char> alphabet;
    for(int i=1; i<=26; i++){
        alphabet[i] = 'A'+ i-1;
    }
    string s1;
    while(s >0){
        int r = s%26;
        if(r == 0){
            s1 = 'Z' + s1;
            s = (s-26)/26;
        }else{
            s1 = alphabet[r] + s1;
            s = (s-r)/26;
        }
    }
    return s1;
}
int main(){
    int s;
    cin >> s; 
    cout << trung(s);
    return 0;
}