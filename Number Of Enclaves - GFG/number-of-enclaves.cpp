//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
     private:
    void dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>&vis){
         int n=grid.size();
        int m=grid[0].size();
        vis[row][col]=1;
        int drow[4]={-1,0,1,0};
        int dcol[4]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int newRow=row+drow[i];
            int newCol=col+dcol[i];
            if(newRow>=1 && newRow<n && newCol>=1 && newCol<m && !vis[newRow][newCol] && grid[newRow][newCol]==1)
                dfs(newRow,newCol,grid,vis);
        }
    }
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
         int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
         // traverse first row and last col 
        for(int j=0;j<m;j++){
            //first row
            if(!vis[0][j] && grid[0][j]==1)
               dfs(0,j,grid,vis);
            //first col
            if(!vis[n-1][j] && grid[n-1][j]==1)
                dfs(n-1,j,grid,vis);
        }//traverse first col and last col
        for(int i=0;i<n;i++){
            //first col
            if(!vis[i][0] && grid[i][0]==1)
                dfs(i,0,grid,vis);
            //last col
            if(!vis[i][m-1] && grid[i][m-1]==1)
                dfs(i,m-1,grid,vis);
        }
        int cnt=0;
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(!vis[i][j] && grid[i][j]==1)
                    cnt++;
            }
        }
        return cnt;
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
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends