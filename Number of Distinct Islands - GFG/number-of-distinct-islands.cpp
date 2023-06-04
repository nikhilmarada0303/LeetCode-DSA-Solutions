//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
    void dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& vis,vector<pair<int,int>>&v,
    int row0,int col0){
         int n=grid.size();
        int m=grid[0].size();
        vis[row][col]=1;
        v.push_back({row-row0,col-col0});
        int delRow[]={-1,0,1,0};
	    int delCol[]={0,1,0,-1};
	      for(int i=0;i<4;i++){
            int newRow=row+delRow[i];
            int newCol=col+delCol[i];
            if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && !vis[newRow][newCol] && grid[newRow][newCol]==1)
                dfs(newRow,newCol,grid,vis,v,row0,col0);
    }}
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        set<vector<pair<int,int>>>set;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                vector<pair<int,int>>v;
                dfs(i,j,grid,vis,v,i,j);
                set.insert(v);
                }
            }
        }return set.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends