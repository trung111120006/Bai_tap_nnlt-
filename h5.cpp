#include <bits/stdc++.h>

using namespace std;
int main() {
    int letter = 0, line = 0, word =0;
    ifstream cin("h5.txt");
    string s;
    getline(cin, s);
    for(int i = 0; i< s.length(); i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            letter++;
        }
        if(s[i]==' ' && s[i-1]!=' '){
            word++;
        }
        if(s[i]=='\n'){
            line++;
        }
    }
    cout << "Letters: " << letter << endl;
    cout << "Words: " << word+1 << endl;
    cout << "Lines: " << line+1 << endl;
    return 0;
}