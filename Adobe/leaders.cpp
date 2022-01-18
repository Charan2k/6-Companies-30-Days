#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> leaders(int arr[], int n){
    vector<int> ans;
    int ma = INT_MIN;
    for(int i=n-1; i>=0; i--){
        if(arr[i]>ma){
            ma = arr[i];
            ans.push_back(ma);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    vector<int> ans = leaders(arr,n);
    for(auto i: ans){
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}