#include<iostream>
#include<vector>
using namespace std;

void transpose(vector<vector<int> >& matrix, int n){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

void swapRows(vector<vector<int> >& matrix, int n){
    for(int i=0; i<n/2; i++){
        for(int j=0; j<n; j++){
            int temp = matrix[i][j];
            matrix[i][j] = matrix[n-i-1][j];
            matrix[n-i-1][j] = temp;
        }
    }
}

void rotate(vector<vector<int> >& matrix, int n){
    transpose(matrix,n);
    swapRows(matrix, n);
}

int main(){
    int n;
    cin >> n;
    vector<vector<int> > matrix(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> matrix[i][j];
        }
    }
    rotate(matrix,n);
    for(auto i: matrix){
        for(auto j: i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}