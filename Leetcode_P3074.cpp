class Solution {
public:

    void quick_sort(vector<int>& a, int low, int high) {
        if (low >= high) return;

        int pivot = a[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (a[j] < pivot) {
                ++i;
                swap(a[i], a[j]);
            }
        }

        swap(a[i + 1], a[high]);
        int pi = i + 1;

        quick_sort(a, low, pi - 1);
        quick_sort(a, pi + 1, high);
    }

    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {

        long long tong = 0;
        for (int x : apple) tong += x;

        // gọi quick sort đúng cách
        quick_sort(capacity, 0, capacity.size() - 1);

        // duyệt từ hộp lớn nhất về nhỏ nhất
        for (int i = capacity.size() - 1; i >= 0; i--) {
            tong -= capacity[i];
            if (tong <= 0)
                return capacity.size() - i;
        }

        // fallback — trong mọi trường hợp phải return
        return capacity.size();
    }
};
