#include  <bits/stdc++.h>
using namespace std;

void counting_sort(vector<int>& arr) {
    int max_val = *max_element(arr.begin(), arr.end()); // Find the maximum value in the array
    vector<int> count(max_val + 1, 0);
    
    for (int num : arr) { 
        count[num]++;
    }
    
    int index = 0;
    for (int i = 0; i <= max_val; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }
}  
int main() {
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    counting_sort(arr);
    
    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}   