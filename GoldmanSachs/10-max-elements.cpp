#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> tenMaxNumbers(int arr[], int n){
    vector<int> heap;
    for(int i=0; i<10; i++){
        heap.push_back(arr[i]);
    }
    sort(heap.begin(), heap.end());
    for(int i=10; i<n; i++){
        if(arr[i]>heap[0]){
            heap[0] = arr[i];
            sort(heap.begin(), heap.end());
        }
    }
    sort(heap.begin(), heap.end());
    return heap;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    vector<int> ans = tenMaxNumbers(arr,n);
    for(auto i: ans){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}