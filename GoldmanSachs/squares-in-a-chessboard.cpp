#include<iostream>
#include<math.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

long long numOfSquares(int n){
    long long sum = 0;
    rep(i,1,n+1){
        sum += pow(i,2);
    }
    return sum;
}

int main(){
    int n;
    cin >> n;
    long long ans = numOfSquares(n);
    cout << ans << endl;
    return 0;
}