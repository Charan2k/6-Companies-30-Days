#include<iostream>
using namespace std;

int countSubArrayProductLessThanK(int arr[], int n, int k){
    int product = 1;
    int count = 0;
    int l=0, r=0;
    while(r<n){
        product = product*arr[r];
        while(product>=k){
            product = product/arr[l];
            l++;
        }
        if(product>0){
            count += (r-l) + 1;
        }
        r++;
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