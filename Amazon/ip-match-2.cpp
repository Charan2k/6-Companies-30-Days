#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector<int> maxOfSubArrays(int arr[], int n, int k){
    vector<int> ans;
    multiset<int, greater<int> > window;
    for(int i=0; i<k; i++){
        window.insert(arr[i]);
    }
    ans.push_back(*window.begin());
    for(int i=k; i<n; i++){
        window.insert(arr[i]);
        auto it = window.find(arr[i-k]);
        window.erase(it);
        ans.push_back(*window.begin());
    }
    return ans;
}

int main(){
    int n,k;
    cin >> n >> k;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    vector<int> ans = maxOfSubArrays(arr,n,k);
    for(auto i: ans){
        cout << i << " "; 
    }
    cout << endl;
    return 0;
}