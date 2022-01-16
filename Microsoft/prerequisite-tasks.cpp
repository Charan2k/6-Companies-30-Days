#include"stdc++.h"
using namespace std;

bool circle(int i, vector<bool>& visited, vector<bool>& dfsvisit, vector<vector<int> >& graph){
    visited[i] = true;
    dfsvisit[i] = true;
    for(auto it: graph[i]){
        if(!visited[it]){
            if(circle(it,visited,dfsvisit,graph)){
                return true;
            }
        }
        else if(dfsvisit[it]){
            return true;
        }
    }
    dfsvisit[i] = false;
    return false;
}

bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
    // Code here
    vector<vector<int> > graph(N);
    for(auto i: prerequisites){
        graph[i.first].push_back(i.second);
    }
    // for(auto i: graph){
    //     for(auto j: i){
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    vector<bool> visited(N,false);
    vector<bool> dfsvisit(N,false);
    for(int i=0; i<N; i++){
        if(!visited[i]){
            if(circle(i,visited,dfsvisit,graph)){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int N, P;
    vector<pair<int, int> > prerequisites;
    cin >> N;
    cin >> P;
    for (int i = 0; i < P; ++i) {
        int x, y;
        cin >> x >> y;
        prerequisites.push_back(make_pair(x, y));
    }
    if (isPossible(N, prerequisites))
        cout << "Yes";
    else
        cout << "No";
    cout << endl;
	
	return 0;
}