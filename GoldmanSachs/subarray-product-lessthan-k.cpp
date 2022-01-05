#include<iostream>
using namespace std;

int countSubArrayProductLessThanK(int arr[], int n, int k){
    int x = 1;
    int count = 0;
    for(int i=0; i<n; i++){
        if(arr[i]<k){
            count++;
        }
        if(x*arr[i]<k){
            x = x*arr[i];
            count+=2;
        }
    }
    return count;
}

int main(){
    int n,k;
    cin >> n >> k;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int ans = countSubArrayProductLessThanK(arr,n,k);
    cout << ans << endl;
    return 0;
}