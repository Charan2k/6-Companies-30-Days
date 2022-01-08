#include<iostream>
#include<vector>
using namespace std;

vector<int> maxOfSubArrays(int arr[], int n, int k){
    vector<int> ans;
    for(int i=0; i<n-k+1; i++){
        int max = 0;
        for(int j=i; j<i+k; j++){
            if(arr[j]>max){
                max = arr[j];
            }
        }
        ans.push_back(max);
    }
    return ans;
}

int main(){
    int n,k;
    cin >> n >> k;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    vector<int> ans = maxOfSubArrays(arr,n,k);
    for(auto i: ans){
        cout << i << " "; 
    }
    cout << endl;
    return 0;
}