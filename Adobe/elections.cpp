#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<vector>

using namespace std;

vector<string> winner(string arr[],int n)
{
    map<string,int> m;
    int ma = 0;
    string winner;
    for(int i=0; i<n; i++){
        m[arr[i]]++;
    }
    for(auto i: m){
        if(i.second > ma){
            ma = i.second;
            winner = i.first;
        }
    }
    vector<string> ans;
    ans.push_back(winner);
    ans.push_back(to_string(ma));
    return ans;
}

int main(){
    int n;
    cin>>n;
    string arr[n];
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<string> result = winner(arr,n);
    cout<<result[0] << " " << result[1] << endl;
    return 0;
}