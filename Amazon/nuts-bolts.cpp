#include<iostream>
#include<algorithm>
using namespace std;

void fitNutsBolts(char *nuts, char *bolts, int n){
    sort(nuts, nuts+n);
    sort(bolts, bolts+n);
}

int main(){
    int n;
    cin >> n;
    char nuts[n], bolts[n];
    for(int i=0; i<n; i++){
        cin >> nuts[i];
    }
    for(int i=0; i<n; i++){
        cin >> bolts[i];
    }
    fitNutsBolts(nuts, bolts, n);
    cout << nuts << endl;
    cout << bolts << endl;
    return 0;
}