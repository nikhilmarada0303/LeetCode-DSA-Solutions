class Solution {
public:
    int func(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(row==0 && col==0) return 1;
        if(row>=0 && col>=0 && grid[row][col]==1) return 0;
        if(row<0 || col<0) return 0;
        
        if(dp[row][col]!=-1) return dp[row][col];
        int left=func(row,col-1,grid,dp);
        int up=func(row-1,col,grid,dp);
        return dp[row][col]=left+up;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[n-1][m-1]==1 || grid[0][0]==1) return 0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return func(grid.size()-1,grid[0].size()-1,grid,dp);
    }
};