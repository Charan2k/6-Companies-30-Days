#include<iostream>
using namespace std;

int maxProfit(int arr[], int n){
    if(n==1){
        return arr[0];
    }
    if(n<3){
        return max(arr[0],arr[1]);
    }
    int fs = arr[0];
    int ss = max(arr[0],arr[1]);
    int cur;
    for(int i=2; i<n; i++){
        cur = max(fs+arr[i],ss);
        fs = ss;
        ss = cur;
    } 
    return max(ss,cur);
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int ans = maxProfit(arr, n);
    cout << ans << endl;
    return 0;
}