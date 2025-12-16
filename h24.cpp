#include <bits/stdc++.h>

using namespace std;
class book{
    private : 
    string title; 
    string price;
    public : 
    book(string t, string p){
        title = t; 
        price = p;
    }
    book(const book &b){
        title = b.title; 
        price = b.price;
    }
    void setTitle(string t, string p){
        title = t;
        price = p;
    }
    void display(){
        cout << "Title: " << title << ", Price: " << price << endl;
    }
};
int main(){
    book b1("C++ Programming", "29");
    book b2(b1);
    b1.setTitle("Java Programming", "35");
    b1.display();
    b2.display();
    return 0;
}