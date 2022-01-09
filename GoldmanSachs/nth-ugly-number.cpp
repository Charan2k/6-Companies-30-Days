#include<iostream>
#include<unordered_set>
#include<set>
#include<unordered_map>
#include<iterator>
#include<vector>
using namespace std;

int nthUglyNumber(int n){
    int m=1;
    set<int> s;
    set<int>::iterator it;
    s.insert(m);
    it = s.begin();
    for(int i=1; i<=n; i++){
        m = *it;
        s.insert(m*2);
        s.insert(m*3);
        s.insert(m*5);
        it++;
    }
    int i=1;
    for(it = s.begin(); it!=s.end(); it++){
        if(i==n){
            return *it;
        }
        i++;
    }
}

int main(){
    int n;
    cin >> n;
    int ans = nthUglyNumber(n);
    cout << ans << endl;
    return 0;
}