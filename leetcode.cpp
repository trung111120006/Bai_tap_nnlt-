 #include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int k;
    cin >> s >> k;
    int n = s.length();
    for(int i =0; i<k/2; i++){
        swap(s[i], s[k-i-1]);
    }
    cout << s << endl;
    return 0;
}
