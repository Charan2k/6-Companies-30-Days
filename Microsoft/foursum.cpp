#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > findQuadruplets(vector<int> arr, int n, int target){
    set<vector<int>> sol;
    vector<vector<int>> ans;

    vector<int> v;
    sort(arr.begin(),arr.end());
    int i,j,low,high;
    if(n<4){
        return ans;
    }
    for(i=0;i<n-3;i++)
    {
        for(j=i+1;j<n-2;j++)
        {
            low=j+1;
            high=n-1;
            while(low<high)
            {
                int sum = arr[i]+arr[j]+arr[low]+arr[high];
                if(sum==target)
                {
                    v.push_back(arr[i]);
                    v.push_back(arr[j]);  
                    v.push_back(arr[low]);
                    v.push_back(arr[high]);
                    sol.insert(v);
                    v.clear();
                    low++;
                    high--;
                }
                else if(sum>target){
                    high--;
                }
                else{
                    low++;
                }
            }
        }
    }
    ans.insert(ans.begin(), sol.begin(), sol.end());
    return ans;
}

int main(){
    int n, target;
    cin >> n >> target;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    vector<vector<int> > ans = findQuadruplets(arr,n,target);
    for(auto i: ans){
        cout << "[ ";
        for(auto j: i){
            cout << j << " ";
        }
        cout << "]\n";
    }
    return 0;
}