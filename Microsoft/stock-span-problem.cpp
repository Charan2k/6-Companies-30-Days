#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> calculateSpan(int price[], int n){
    stack<pair<int,int> > st;
    vector<int> ans;
    for(int i=0;i<n;i++){
        int day=1;
        while(!st.empty() and st.top().first<=price[i]){
            day+=st.top().second;
            st.pop();
        }
        st.push(make_pair(price[i],day));
        ans.push_back(day);
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    vector<int> ans = calculateSpan(arr,n);
    for(auto i: ans){
        cout << i << " ";
    }
    return 0;
}