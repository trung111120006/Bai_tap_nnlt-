#include <bits/stdc++.h>
using namespace std;

void Combine_Chunk(int P, string combo, vector<string> &CHUNK_COMBO_OPTIONS){
    if(combo.length() == P){
        CHUNK_COMBO_OPTIONS.push_back(combo);
        return;
    }
    for(char i ='0'; i <= '2'; i++){
        combo.push_back(i);
        Combine_Chunk(P, combo, CHUNK_COMBO_OPTIONS);
        combo.pop_back();
    }
}

int main(){
    int P;
    cin >> P;
    vector<string> CHUNK_COMBO_OPTIONS;

    Combine_Chunk(P, "", CHUNK_COMBO_OPTIONS);
    for(int i =0; i< CHUNK_COMBO_OPTIONS.size(); i++){
        cout << CHUNK_COMBO_OPTIONS[i] << "\n";
    }
    return 0;
}
