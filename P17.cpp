#include <bits/stdc++.h>
using namespace std;

vector<string> digits(string n) {
    if (n.empty()) return {};
    map<char, string> digit_map = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };
    vector<string> result = {""};
    for (char digit : n) {
        if (digit_map.find(digit) == digit_map.end()) continue;
        vector<string> temp;
        for (const string& prefix : result) {
            for (char c : digit_map[digit]) {
                temp.push_back(prefix + c);
            }
        }
        result.swap(temp);
    }
    return result;
}
int main() {
    string n;
    cin >> n;
    vector<string> result = digits(n);
    for (const string& s : result) {
        cout << s << " ";
    }
    return 0;
}