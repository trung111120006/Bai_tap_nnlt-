#include <bits/stdc++.h>
using namespace std;

void binary_search(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            cout << "Element found at index: " << mid << endl;
            return;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << "Element not found in the array." << endl;
}
int main() {
    vector<int> arr = {2, 3, 4, 10, 40};
    int target = 10;
    
    binary_search(arr, target);
    
    return 0;
}