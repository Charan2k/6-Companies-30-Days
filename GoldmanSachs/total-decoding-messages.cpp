#include<iostream>
#include<memory.h>
using namespace std;
// int N=10001;
long long countWays(string str){
    int n = str.length();
    if(n==0 || str[0]=='0'){
        return 0;
    }
    // long long dp[n+1];
    // for(int i=0; i<n+1; i++){
    //     dp[i]=0;
    // }
    // dp[0] = 1;
    // dp[1] = 1;
    // int n1,n2;
    int count1 = 1;
    int count2 = 1;
    for(int i=1; i<n; i++){
        // if(str[i]=='0'){
        //     if(str[i-1]>2){
        //         return 0;
        //     }
        //     else{
        //         dp[i+1] = dp[i-1];
        //     }
        // }
        // else{
        //     n1 = str[i];
        //     n2 = str[i-1];
        //     num = n2*10 + n1;
        //     if(num<=26){
        //         dp[i+1] = dp[i]+dp[i-1];
        //     }
        // }
        int count = 0;
        int d1 = str[i]-'0';
        if(d1>0) count += count2;
        int d2 = str[i-1]-'0';
        int num = 10*d2 + d1;
        if(num >= 10 && num<=26){
            count += count1;
        }
        count1 = count2;
        count2 = count;
    }
    return count2;
}

int main(){
    string s;
    cin >> s;
    long long ans = countWays(s);
    cout << ans << endl;
    return 0;
}