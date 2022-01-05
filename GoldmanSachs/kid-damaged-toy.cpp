#include<iostream>
using namespace std;

int getKidNumber(int n, int m, int k){
    // if((m+k-1)%n == 0){
    //     return n;
    // }else{
    //     return (m+k-1)%n;
    // }
    int ans = (m+k-1)%n;
    if(ans){
        return ans;
    }
    else{
        return n;
    }
}

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    int ans = getKidNumber(n,m,k);
    cout << ans << endl;
    return 0;
}