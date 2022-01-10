#include<iostream>
using namespace std;

int numWays(int n){
    return (n/2)+1;
}

int main(){
    int n;
    cin >> n;
    int ans = numWays(n);
    cout << ans << endl;
    return 0;
}