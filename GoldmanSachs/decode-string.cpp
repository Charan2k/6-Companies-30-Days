#include<iostream>
using namespace std;

string decodeUtil(string encoded, int& idx){
    string ans;
    while(idx<encoded.length() && encoded[idx]!=']'){
        if(isdigit(encoded[idx])){
            int k=0;
            while(isdigit(encoded[idx]) && idx<encoded.length()){
                k = k*10 + (encoded[idx]-'0');
                idx++;
            }
            idx++;
            string intr = decodeUtil(encoded, idx);
            while(k--){
                ans += intr;
            }
            idx++;
        }
        else{
            ans += encoded[idx];
            idx++;
        }
    }
    return ans;
}

string decode(string encoded){
    int i=0;
    return decodeUtil(encoded, i);
}

int main(){
    string encoded;
    cin >> encoded;
    string decoded = decode(encoded);
    cout << decoded << endl;
    return 0;
}