#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {        
        vector<vector<string>> ans;
        bool check[n];
        for(int i=0; i<n; i++){
            check[i] = true;
        }
        for(int j=0; j<s.length(); j++){
            bool found = false;
            vector<string> st;
            for(int i=0; i<n; i++){
                if(contact[i][j]==s[j] && check[i]){
                    st.push_back(contact[i]);
                    found = true;
                    check[i] = true;
                }
                else{
                    check[i] = false;
                }
            }
            if(found){
                ans.push_back(st);
            }
            else{
                ans.push_back({{"0"}});
            }
        }
        return ans;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
} 