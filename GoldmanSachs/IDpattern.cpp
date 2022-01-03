#include<iostream>
#include<stack>
using namespace std;

string generateNumber(string pattern){
    stack<int> st;
    int k = 1;
    st.push(k);
    string ans;
    for(int i=0; i<pattern.length(); i++){
        if(pattern[i]=='D'){
            st.push(++k);
        }
        if(pattern[i]=='I'){
            while(!st.empty()){
                ans += to_string(st.top());
                st.pop(); 
            }
            st.push(++k);
        }
    }
    while(!st.empty()){
        ans += to_string(st.top());
        st.pop();
    }
    return ans;
}

int main(){
    string pattern;
    cin >> pattern;
    string ans = generateNumber(pattern);
    cout << ans;
    return 0;
}
