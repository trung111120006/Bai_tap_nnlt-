#include <iostream>
#include <string>
using namespace std;

int main() {
    string a;
    cin >> a;

    for (int i = 1; i < a.length() - 1; i++) {
        int left = a[i - 1] - '0';
        int right = a[i + 1] - '0';

        if (a[i] == '+') cout << left + right;
        else if (a[i] == '-') cout << left - right;
        else if (a[i] == '*') cout << left * right;
        else if (a[i] == '/') cout << left / right;
    }
}
