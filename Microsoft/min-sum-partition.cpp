#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void solve(int index, int n, int arr[], vector<int>& s1, vector<int>& s2, int& mi){
    if(index>=n){
        int sum1 = 0;
        for(auto i: s1) {
            sum1 += i;
        }
        int sum2 = 0;
        for(auto i: s2){
            sum2 += i;
        }
        int diff = abs(sum1-sum2);
        mi = min(mi,diff);
        return;
    }
    s1.push_back(arr[index]);
    solve(index+1,n,arr,s1,s2,mi);
    s1.pop_back();
    
    s2.push_back(arr[index]);
    solve(index+1,n,arr,s1,s2,mi);
    s2.pop_back();
}

int minDifference(int arr[], int n)  { 
    // Your code goes here
    vector<int> s1;
    vector<int> s2;
    int mi = INT_MAX;
    solve(0,n,arr,s1,s2,mi);
    return mi;
} 
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int ans = minDifference(arr,n);
    cout << ans << "\n";
    return 0;
}