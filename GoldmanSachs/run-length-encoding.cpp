#include<iostream>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

string encode(string src){     
  //Your code here 
  int k = 0;
  int count = 1;
  string encoded = "";
  char ch=src[0];
  rep(i,1,src.length()){
      ch = src[k];
      if(src[i] == ch){
          count++;
      }
      else{
          encoded += ch;
          encoded += to_string(count);
          count = 1;
          k = i;
          ch = src[k];
      }
  }
  encoded += ch;
  encoded += to_string(count);
  return encoded;
}     


int main(){
    string src;
    cin >> src;
    string ans = encode(src);
    cout << ans << endl;
    return 0;
}
