#include<bits/stdc++.h>
using namespace std;

// Function to check if the move is valid
bool isValidMove(vector<vector<int>>& grid, int x, int y, vector<vector<bool>>& visited) {
    int m = grid.size();
    int n = grid[0].size();
    return (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 0 && !visited[x][y]);
}

// DFS to go in every path ; 
bool dfs(vector<vector<int>>& grid, int x, int y, int exitx, int exity, vector<vector<bool>>& visited) {
    if (x == exitx && y == exity) {
        return true;
    }

    visited[x][y] = true;

   
    vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (auto di: d) {
        int new_x = x + di.first;
        int new_y = y + di.second;

        if (isValidMove(grid, new_x, new_y, visited)) {
            if (dfs(grid, new_x, new_y, exitx, exity, visited)) {
                return true;
            }
        }
    }

    return false;
}
void solve(){
  int m,n ; 
  cin>>m>>n ; 
  vector<vector<int>>grid(m,vector<int>(n));
  for(int  i=0 ; i<m ; i++){
    for(int j=0 ;j<n;j++ ){
cin>>grid[i][j];
    }
  }
  int x, y; 
  cin>>x>>y; 
  int exit_x,exit_y; 
  cin>>exit_x>>exit_y; 
   vector<vector<bool>> visited(m, vector<bool>(n, false));

  return dfs(grid, x, y, x, y, visited);
}
int main() {
   
int t; 
cin>>t; 
while(t--){
  solve();
}
    return 0;
}
