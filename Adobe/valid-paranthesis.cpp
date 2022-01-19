#include<iostream>
#include<vector>
using namespace std;

void solve(int left, int right, string curr, vector<string>& ans){
    if(left == 0 && right == 0){
        ans.push_back(curr);
        return;
    }
    if(left>0){
        curr.push_back('(');
        solve(left-1,right,curr,ans);
        curr.pop_back();
    }
    if(right>left){
        curr.push_back(')');
        solve(left,right-1,curr,ans);
        curr.pop_back();
    }
}

vector<string> generate(int n){
    vector<string> ans;
    int left = n;
    int right = n;
    string curr = "";
    solve(left,right,curr,ans);
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<string> ans = generate(n);
    for(auto i: ans){
        cout << i << "\n";
    }
    return 0;
}