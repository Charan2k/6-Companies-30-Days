#include"stdc++.h"
using namespace std;

int minSteps(int D){
    int steps = 0;
    int sum = 0;
    while(sum<D) {
        sum+=steps;
        steps++;
    }
    while((sum-D)%2) {
        sum+=steps;
        steps++;
    }
    return steps-1;
}

int main(){
    int D;
    cin>>D;
    cout << minSteps(D) << "\n";
    return 0;
}