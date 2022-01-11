#include<iostream>
#include<vector>
using namespace std;

vector<int> spiralOrderTraversal(vector<vector<int> >& matrix, int r, int c){
    int left = 0, right = c-1;
    int top = 0, bottom = r-1;
    int count = 0;
    vector<int> ans;
    while(left<=right && top<=bottom){
        if(count<r*c)
        for(int i=left; i<=right; i++){
            ans.push_back(matrix[top][i]);
            count++;
        }
        top++;
        if(count<r*c)
        for(int i=top; i<=bottom; i++){
            ans.push_back(matrix[i][right]);
            count++;
        }
        right--;
        if(count<r*c)
        for(int i=right; i>=left; i--){
            ans.push_back(matrix[bottom][i]);
            count++;
        }
        bottom--;
        if(count<r*c)
        for(int i=bottom; i>=top; i--){
            ans.push_back(matrix[i][left]);
            count++;
        }
        left++;
    }
    return ans;
}

int main(){
    int r,c;
    cin >> r >> c;
    vector<vector<int> > matrix(r, vector<int>(c));
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> matrix[i][j];
        }
    }
    vector<int> ans = spiralOrderTraversal(matrix,r,c);
    for(auto i: ans){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}