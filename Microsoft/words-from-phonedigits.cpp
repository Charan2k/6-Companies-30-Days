#include<bits/stdc++.h>
using namespace std;

string phone[10] = {
    "",
    "",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz" 
};

void solve(int index, string s, string curr, vector<string>& ans){
    if(index == s.length()){
        ans.push_back(curr);
        return;
    }
    int d = s[index]-48;
    string letters = phone[d];
    for(int i=0; i<phone[d].length(); i++){
        curr += phone[d][i];
        solve(index+1, s, curr, ans);
        curr[curr.length()-1] = '\0';
    }
}

vector<string> generateNames(string s){
    vector<string> ans;
    string curr;
    solve(0,s,curr,ans);
    return ans;
}

int main(){
    string s;
    cin >> s;
    vector<string> ans = generateNames(s);
    for(auto i: ans){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}