#include<iostream>
using namespace std;

int GCD(int a, int b){
    if(a<b){
        return GCD(b,a);
    }
    if(b==0) return a;
    else return GCD(b,a%b);
}

bool isValid(string str1, string str2, int gcd){
    int j = 0;
    for(int i=0; i<str1.length(); i++){
        if(str1[i] != str2[j%gcd]){
            return false;
        }
        j++;
    }
    return true;
}

string gcdOfStrings(string str1, string str2){
    int l1 = str1.length();
    int l2 = str2.length();
    int gcd = GCD(l1,l2);
    string ans;
    if(l1>l2){
        if(isValid(str1,str2,gcd)){
            return string(str1.begin(), str1.begin()+gcd);
        }
    }
    if(l2>l1){
        if(isValid(str2,str1,gcd)){
            return string(str2.begin(), str2.begin()+gcd);
        }
    }
    return "";

}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    string ans = gcdOfStrings(s1,s2);
    cout << ans << endl;
    return 0;
}