#include<iostream>
using namespace std;

struct rect{
    int x;
    int y;
};

bool overlaps(struct rect l1, struct rect r1, struct rect l2, struct rect r2){
    if(l2.x > r1.x || r2.x < l1.x || r2.y > l1.y || l2.y < r1.y){
        return false;
    }
    return true;
}

int main(){
    struct rect l1,r1,l2,r2;
    cin >> l1.x >> l1.y;
    cin >> r1.x >> r1.y;
    cin >> l2.x >> l2.y;
    cin >> r2.x >> r2.y;
    if(overlaps(l1,r1,l2,r2)){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    cout << endl;
    return 0;
}