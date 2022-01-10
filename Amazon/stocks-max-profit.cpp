#include<iostream>
#include<climits>
using namespace std;

int maxProfit(int arr[], int n, int k){
    int dp[k+1][n];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=k;i++)
    {
        int mx=INT_MIN;
        for(int j=1;j<n;j++)
        {
            mx=max(mx,dp[i-1][j-1]-arr[j-1]);
            dp[i][j]=max(dp[i][j-1],mx+arr[j]);
        }
    }
    return dp[k][n-1];
}

int main(){
    int k,n;
    cin >> k >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int ans = maxProfit(arr,n,k);
    cout << ans << endl;
    return 0;
}