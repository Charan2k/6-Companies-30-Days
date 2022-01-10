#include<iostream>
#include<vector>
using namespace std;

int sizeOfLongestMountain(vector<int>& arr) {
    int mount=0;
    int i=0;
    int n=arr.size();
    while(i<n)
    {
        int j=i+1,k=i;
        while(j<n && k<n && arr[j]>arr[k])
        {
            j++;
            k++;
        }
        if(k!=i)
        {
            int temp=k;
            while(j<n && k<n && arr[j]<arr[k])
            {
                j++;
                k++;
            }
            if(k!=temp) 
            {
                mount=max(mount,k-i+1);
            }
            
        }
        i++;
    }
    return mount;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int ans = sizeOfLongestMountain(arr);
    cout << ans << endl;
    return 0;
}