#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<string> > groupAnagrams(vector<string> strings){
    int length = strings.size();
    vector<string> copy = strings;
    for(int i=0; i<length; i++){
        sort(copy[i].begin(), copy[i].end());
    }
    vector<vector<string> > ans;
    vector<string> group;
    bool flag[length];
    for(int i=0; i<length; i++){
        flag[i] = false;
    }
    for(int i=0; i<length; i++){
        if(!flag[i]){
            group.push_back(strings[i]);
            flag[i] = true;
        }
        for(int j=i+1; j<length; j++){
            if(!flag[j] && (copy[i]==copy[j])){
                flag[j] = true;
                group.push_back(strings[j]);
            }
        }
        if(group.size()!=0){
            ans.push_back(group);
            group.clear();
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<string> strings;
    string str;
    for(int i=0; i<n; i++){
        cin >> str;
        strings.push_back(str);
    }
    vector<vector<string> > ans = groupAnagrams(strings);
    for(auto i: ans){
        for(auto j: i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}