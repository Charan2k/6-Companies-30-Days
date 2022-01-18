#include<iostream>
#include<vector>
using namespace std;


vector<int> findSubArray(int arr[], int n, int target){
    int sum = 0;
    int left = 0;
    int right = 0;
    while(left<n){
        if(sum == target){
            break;
        }
        if(sum < target){
            sum += arr[right];
            right++;
        }
        else{
            sum -= arr[left];
            left++;
        }
    }
    vector<int> ans;
    if(sum != target){
        ans.push_back(-1);
        return ans;
    }
    ans.push_back(left+1);
    ans.push_back(right);
    return ans;
}

int main(){
    int n, target;
    cin >> n >> target;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    vector<int> ans = findSubArray(arr,n,target); 
    // cout << ans[0] << " " << ans[1] << "\n";
    for(auto i: ans){
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}