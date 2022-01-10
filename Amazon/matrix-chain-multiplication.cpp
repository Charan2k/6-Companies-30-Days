#include<iostream>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

ll dp[1002][1002];
ll bracket[1002][1002];

void printParenthesis(int i, int j, int n, char &name) {
    if (i == j){
        cout << name++; 
        return; 
    } 
    cout << "("; 
    printParenthesis(i, bracket[i][j], n, name); 
    printParenthesis(bracket[i][j] + 1, j, n, name); 
    cout << ")"; 
} 
int solve(int arr[], int i, int j){
    if(i>=j)
        return 0;
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans = INT_MAX;
    for(int k=i;k<=j-1;k++){
        int left,right;
        if(dp[i][k]!=-1)
            left = dp[i][k];
        else 
            left = solve(arr,i,k);
        if(dp[k+1][j]!=-1)
            right = dp[k+1][j];
        else 
            right = solve(arr,k+1,j); 
        int temp = left+right+ arr[i-1]*arr[k]*arr[j];
        if(temp<ans){
            ans = temp;
            bracket[i][j]=k;
        }
    }
    return dp[i][j] = ans;
}

int main() 
{ 
    memset(dp,-1,sizeof(dp));
    memset(bracket,-1,sizeof(bracket));
    int n;
    cin>>n;
    int v[n];
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    solve(v,1,n-1);
    char name='A';
    printParenthesis(1, n-1, n, name); 
    cout<<endl;
    return 0; 
}