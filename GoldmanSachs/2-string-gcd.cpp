#include<iostream>
using namespace std;

int GCD(int a, int b){
    if(a<b){
        return GCD(b,a);
    }
    if(b==0) return a;
    else return GCD(b,b%a);
}

string gcdOfStrings(string str1, string str2) {
    int l1 = str1.length();
    int l2 = str2.length();
    int gcd = GCD(l1, l2);
    int pos1 = string::npos;
    int pos2 = string::npos;
    int which = 0;
    if(l1==l2){
        if(str1.find(str2) != string::npos){
            return str1;
        }
    }
    else if(l1>l2){
        pos1 = str1.find(str2);
        if(pos1 != string::npos){
            pos2 = str1.find(str2, pos1+1);
        }
        if(pos2 != string::npos){
            which = 1;
        }
    }
    else{
        pos1 = str2.find(str1);
        if(pos1 != string::npos){
            pos2 = str2.find(str1,pos1+1);
        }
        if(pos2 != string::npos){
            which = 2;
        }
    }
    if(which != 0){
        if(which == 1 && pos2-pos1 <= gcd){
            string ans = string(str1.begin(), str1.begin()+gcd);
            return ans;
        }
        if(which == 2 && pos2-pos1 <= gcd){
            string ans = string(str2.begin(), str2.begin()+gcd);
            return ans;
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