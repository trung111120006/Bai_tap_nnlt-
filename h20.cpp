#include <bits/stdc++.h>
using namespace std;

void dictionary(string &word){
    map<string, string> dict; 
    dict["apple"] = "Táo";
    dict["anana"] = "Chuối";
    dict["orange"] = "Cam";
    dict["grapes"] = "Nho";
    dict["pineapple"] = "Dứa";
    dict["mango"] = "Xoài";
    dict["strawberry"] = "Dâu tây";
    dict["watermelon"] = "Dưa hấu";
    dict["peach"] = "Đào";
    dict["cherry"] = "Anh đào";
    dict["hello"] = "Xin chào";
    dict["goodbye"] = "Tạm biệt";
    dict["please"] = "Làm ơn";
    dict["thank"] = "Cảm ơn";
    dict["chair"] = "Cái ghế";
    dict["table"] = "Cái bàn";
    dict["computer"] = "Máy tính";
    dict["phone"] = "Điện thoại";
    dict["book"] = "Quyển sách";
    dict["pen"] = "Cây bút";
    dict["school"] = "Trường học";
    dict["teacher"] = "Giáo viên";
    dict["student"] = "Học sinh";
    dict["library"] = "Thư viện";
    dict["hospital"] = "Bệnh viện";
    dict["market"] = "Chợ";
    dict["restaurant"] = "Nhà hàng";
    dict["airport"] = "Sân bay";
    dict["station"] = "Ga tàu";
    dict["bank"] = "Ngân hàng";
    dict["hotel"] = "Khách sạn";
    dict["museum"] = "Bảo tàng";
    dict["park"] = "Công viên";
    dict["cinema"] = "Rạp chiếu phim";
    dict["theater"] = "Nhà hát";
    if (dict.find(word) != dict.end()){
        cout << "The Vietnamese translation of " << word << " is: " << dict[word] << "\n";
    } else {
        map <int, string> dem; 
        int n = word.length();
        for(auto &word_pair : dict){
            int dem1 =0 ;
            int m = word_pair.first.length();
            for (int i = 0; i< min(n, m); i++){
                if (word[i] != word_pair.first[i]){
                    break; 
                }else {
                    dem1++;
                }
            if (dem1 >0 ){
                dem[dem1] = word_pair.first;
        }
    }
}
int max = max_element(dem.begin(), dem.end())->first;
    cout << "The same word is:" << dem[max] << "\n";
}
}
int main(){
    string word;
    cin >> word; 
    void (*dictPtr)(string&) = &dictionary;
    dictPtr(word);
    return 0;
}
    