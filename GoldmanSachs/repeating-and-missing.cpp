#include<iostream>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

pair<int,int> findRepNMiss(int arr[], int n){
    int repeating = 0;
    int missing = 0;
    rep(i,0,n){
        int index = abs(arr[i])-1;
        if(arr[index]>0){
            arr[index] = 0-arr[index];
        }
        else{
            repeating = abs(arr[i]);
        }
    }
    rep(i,0,n){
        if(arr[i]>0){
            missing = i+1;
        }
    }
    pair<int,int> ans;
    ans.first = repeating;
    ans.second = missing;
    return ans;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    rep(i,0,n)
        cin >> arr[i];
    pair<int,int> ans = findRepNMiss(arr,n);
    cout << ans.first << " " << ans.second << endl;
    return 0;
}