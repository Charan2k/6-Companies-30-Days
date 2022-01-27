#include<iostream>
#include<vector>
using namespace std;

int areaTillHere(vector<vector<int> >& grid, int x, int y) {
    if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()){
        return 0;
    }
    if(!grid[x][y]) {
        return 0;
    }
    grid[x][y] = 0;
    return 1 + areaTillHere(grid, x - 1, y) 
                + areaTillHere(grid, x + 1, y)
                + areaTillHere(grid, x, y - 1)
                + areaTillHere(grid, x, y + 1)
                + areaTillHere(grid, x-1,y-1)
                + areaTillHere(grid, x+1, y + 1)
                + areaTillHere(grid, x+1,y-1)
                + areaTillHere(grid, x-1,y+1);
                
}
int findMaxArea(vector<vector<int> >& grid) {
    int max_area = 0;
    for(int i = 0; i < grid.size(); ++i) {
        for(int j = 0; j < grid[0].size(); ++j) {
            if(grid[i][j]){
                max_area = std::max(areaTillHere(grid, i, j), max_area);
            }
        }
    } 
    return max_area;
}
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int> > grid(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> grid[i][j];
        }
    }
    int ans = findMaxArea(grid);
    cout << ans << "\n";
    return 0;
}