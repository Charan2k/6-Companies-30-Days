#include<iostream>
using namespace std;

string amendSentence (string s){
    string ans;
    int i=0;
    int n = s.length();
    bool space = false;
    while(i<n){
        if(isupper(s[i])){
            if(space){
                ans += ' ';
            }
            ans += tolower(s[i]);
        }
        else{
            ans += s[i];
        }
        space = true;
        i++;
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    cout << amendSentence(s) << endl;
}