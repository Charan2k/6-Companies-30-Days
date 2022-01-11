#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<string> generateBinaryStrings(int n){
    vector<string> ans;
    string s = "";
    for(int i=1; i<=n; i++){
        int a = i;
        while(a){
            s = to_string(a%2) + s;
            a = a/2;
        }
        ans.push_back(s);
        s = "";
    }
    return ans;
}

vector<string> generateBinaryStringsQueue(int n){
    queue<string> q;
    vector<string> ans;
    q.push("1");
    for(int i=0; i<n; i++){
        ans.push_back(q.front());
        q.push(q.front()+"0");
        q.push(q.front()+"1");
        q.pop();
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    // vector<string> ans = generateBinaryStrings(n);
    vector<string> ans = generateBinaryStringsQueue(n);
    for(auto i: ans){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}