class Solution {
public:
    int func(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(row==0 && col==0) return grid[row][col];
        if(row<0 || col<0) return 1e9;
        
        if(dp[row][col]!=-1) return dp[row][col];
        int left=grid[row][col]+func(row,col-1,grid,dp);
        int right=grid[row][col]+func(row-1,col,grid,dp);
        return dp[row][col]=min(left,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
       return func(n-1,m-1,grid,dp); 
    }
};