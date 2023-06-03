//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
   void dfs(vector<vector<char>> &value , vector<vector<int>>&vis,int row,int col)
    {
        vis[row][col]=1;
        int r= value.size();
        int c= value[0].size();
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
               int newRow=row+i;
               int newCol=col+j;
               
               if(newRow>=0 and newRow<r and newCol>=0 and newCol<c and
               value[newRow][newCol]=='1' and !vis[newRow][newCol])
               {
                   dfs(value,vis,newRow,newCol);
               }
               
            }
        }
    }
  public:
    
    
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    dfs(grid,vis,i,j);
                    cnt++;
                }
            }
        }return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends