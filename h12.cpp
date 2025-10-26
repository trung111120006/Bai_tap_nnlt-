// Bài tính tích 2 ma trận mn và np
#include <iostream>
using namespace std;

int main() {
    int val = 10;      // Biến kiểu int
    int *ptr = &val;   // Con trỏ trỏ tới val
    int **ptr2 = &ptr; // Con trỏ cấp 2 trỏ tới ptr

    // Truy cập giá trị thông qua con trỏ cấp 2
    cout << "Giá trị val: " << val << endl;
    cout << "Giá trị thông qua ptr: " << *ptr << endl;
    cout << "Giá trị thông qua ptr2: " << **ptr2 << endl;

    // Thay đổi giá trị thông qua con trỏ cấp 2
    **ptr2 = 20;
    cout << "Giá trị val sau khi thay đổi: " << val << endl;

    return 0;
}