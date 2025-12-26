#include <bits/stdc++.h>
using namespace std;

bool scheck(const string &s, int l, int r){
    while(l < r){
        if(s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}

string longestPalindrome(string s){
    int n = s.length();
    string res = "";

    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(scheck(s, i, j)){
                if(j - i + 1 > res.length()){
                    res = s.substr(i, j - i + 1);
                }
            }
        }
    }
    return res;
}

int main(){
    string s;
    cin >> s;
    cout << longestPalindrome(s);
    return 0;
}
