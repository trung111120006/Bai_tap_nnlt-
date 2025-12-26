#include <bits/stdc++.h>

using namespace std;
int trung(string s){
    int n = s.size();
    map<char,int> alphabet; 
    for(int i = 0; i<26; i++){
        alphabet[char('a' + i)] = 0;
    }
    for(int i = 0; i<n; i++){
        alphabet[s[i]]++;
    }
    int dem = 0; 
    for(auto x: alphabet){
        if(x.second > 1) dem++;
    }
    return dem;
}