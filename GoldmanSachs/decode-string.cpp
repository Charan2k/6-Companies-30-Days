#include<iostream>
using namespace std;

string decodeUtil(string encoded, int i){
    string ans;
    while(i<encoded.length() && encoded[i]!=']'){
        if(isdigit(encoded[i])){
            int k=0;
            while(i<encoded.length() && isdigit(encoded[i])){
                k = k*10 + encoded[i]-'0';
                i++;
            }
            i++;
            string intr = decodeUtil(encoded,i);
            while(k--){
                ans += intr;
            }
            i++;
        }
        else{
            ans += encoded[i]; 
            i++;
        }
    }
    return ans;
}

string decode(string encoded){
    return decodeUtil(encoded, 0);
}

int main(){
    string encoded;
    cin >> encoded;
    string decoded = decode(encoded);
    cout << decoded << endl;
    return 0;
}