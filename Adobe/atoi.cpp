#include<iostream>
using namespace std;


int atoi(string str) {
    int i=0;
    int n = str.length();
    int num = 0;
    int sign = 1;
    if(str[0] == '-'){
        sign = -1;
        i++;
    }
    while(i<n){
        if(!isdigit(str[i])){
            return -1;
        }
        num = num * 10 + (str[i]-'0');
        i++;
    }
    return sign*num;
}

int main(){
    string s;
    cin>>s;
    cout<<atoi(s)<<endl;
}