#include <bits/stdc++.h>
using namespace std;

int random(int a, int b){
    int x = rand() % (b - a + 1) + a;
    int k = x*(b-a) +a;
    return k;
}
int random_array (int arr[], int n, int k){
    for (int i =0 ; i<k; i++){
        int x = rand() % n;
        return arr[x] ;
    }
}

int main (){
    srand(time(NULL));
    int a, b, n, k;
    int arr[n];
    cin >> a >> b >> n >> k;
    for (int j = 0; j<n; j++){
        cin >> arr[j];
    }
    cout << random(a, b) << endl;
    cout << random_array(arr, n, k) << endl;
    return 0;
}
