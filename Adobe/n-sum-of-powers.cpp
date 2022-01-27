#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
#define mod 1000000007

int solve(int i, int n, int x, vector<vector<int> >& dp){
    if(n==0){
        return 1;
    }
    if(i>n || n<0){
        return 0;
    }
    if(dp[n][i]!=-1) return dp[n][i];
    int p = pow(i,x);
    int take = solve(i+1,n-p,x,dp);
    int notTake = solve(i+1,n,x,dp);
    return dp[n][i] = (take+notTake)%mod;
}

int numWays(int n, int x){
    vector<vector<int> >dp(n+1,vector<int>(n+1,-1));
    return solve(1,n,x,dp);
}

int main(){
    int n, x;
    cin >> n >> x;
    int ans = numWays(n,x);
    cout << ans << "\n";
    return 0;
}