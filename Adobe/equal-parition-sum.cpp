#include<iostream>
#include<vector>
using namespace std;

int equalPartition(int arr[], int n){
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }
    if(sum&1){
        return 0;
    }
    sum = sum/2;
    vector<vector<int> > dp(n+1,vector<int>(sum+1));
    for(int i = 0; i<=n; i++){
        dp[i][0] = 1;
    }
    for(int j=0; j<=sum; j++){
        dp[0][j] = 0;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int ans = equalPartition(arr,n);
    cout << ans << "\n";
    return 0;
}