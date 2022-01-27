#include<iostream>
#include<vector>
using namespace std;

int solve(int i, int j, int arr[], int n, vector<vector<int> >& dp){
    if(i==j){
        return arr[i];
    }
    if(i>j){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int X = arr[i] + min(solve(i+2,j,arr,n,dp), solve(i+1,j-1,arr,n,dp));
    int Y = arr[j] + min(solve(i,j-2,arr,n,dp), solve(i+1,j-1,arr,n,dp));
    return dp[i][j] = max(X,Y);
}

int maxCoins(int arr[], int n){
    vector<vector<int> > dp(n, vector<int>(n,-1));
    return solve(0,n-1,arr,n,dp);
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int ans = maxCoins(arr,n);
    cout << ans << "\n";
    return 0;
}