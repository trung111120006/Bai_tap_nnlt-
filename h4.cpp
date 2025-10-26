#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;
int main() {
    int Lowercase = 0, Uppercase = 0, Digit = 0, SpecialChar = 0;
    string s; 
    while (true) {
        cout << "Enter your password: ";
        getline(cin, s);
        if(s.length() >= 10) {
            break;
        } else {
            cout << "The password must be at least 8 characters long." << endl;
        }
    }
    for(int i=0; i<s.length(); i++) {
        if(s[i]>='A' && s[i]<='Z') {
            Uppercase++;
        }
        if(s[i]>='a' && s[i]<='z') {
            Lowercase++;
        }
        if(s[i]>='0' && s[i]<='9') {
            Digit++;
        }
        if(s[i]=='!' || s[i]=='@' || s[i]=='#' || s[i]=='$' || s[i]=='%' || s[i]=='^' || s[i]=='&' || s[i]=='*' || s[i]=='(' || s[i]==')' || s[i]=='-' || s[i]=='+') {
            SpecialChar++;
        }
    }
    if(Uppercase == 0){ 
        cout << "The password must contain at least one uppercase letter." << endl;
    }else if(Lowercase == 0) {
        cout << "The password must contain at least one lowercase letter." << endl;
    }else if(Digit == 0) {
        cout << "The password must contain at least one digit." << endl;
    }else if(SpecialChar == 0) {
        cout << "The password must contain at least one special character." << endl;
    }else {
        cout << "The password is strong." << endl;
    }
}