#include <bits/stdc++.h>

using namespace std;
int main() {
    int dem[10];
    float k[10];
    for(int i = 0; i<10; i++){
        dem[i] =0;
    }
    int n; 
    cin>>n;
    int m=n;
    while (n>0){
        int number = rand() % 10;
        dem[number]++;
        n--;
    }
    for(int i =0; i<10;i++){
        k[i] = (float)dem[i] / (float)m * 100;
        cout << "Number " << i << " appeared " << dem[i] << " times." << endl;
        cout << "Percentage: " << k[i] << "%" << endl;
    }
    return 0;
}