#include <bits/stdc++.h>
using namespace std;

int combine_digital(vector<int>& digits)
{
    int n = digits.size();
    int dem = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        dem = dem * 10 + digits[i];
    }

    return dem;
}

int main()
{
    vector<int> a = {1, 2, 3, 4};
    cout << combine_digital(a);
    return 0;
}
