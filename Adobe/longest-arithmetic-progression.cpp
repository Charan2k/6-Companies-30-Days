#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
   

int lengthOfLongestAP(int A[], int n) {
    // code here
    if(n<=2) return n;
    
    vector<unordered_map<int,int> > dp(n);
    int ans=0;
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int diff = A[j]-A[i];
            if(dp[i].find(diff)==dp[i].end())
                dp[j][diff] = 2;
            else
                dp[j][diff] = dp[i][diff]+1;
            ans = max(ans,dp[j][diff]);
        }
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
    int ans = lengthOfLongestAP(arr, n);
    cout << ans << "\n";
    return 0;
}