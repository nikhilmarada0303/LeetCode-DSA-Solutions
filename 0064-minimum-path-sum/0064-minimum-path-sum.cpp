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
        vector<vector<int>>dp(n,vector<int>(m,0));
       
        
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(row==0 && col==0) dp[0][0]=grid[0][0];
                else{
                    int left=1e9,right=1e9;
                    if(col>0)
                    left=grid[row][col]+dp[row][col-1];
                    if(row>0)
                    right=grid[row][col]+dp[row-1][col];
                    dp[row][col]=min(left,right);
                }
            }
        }return dp[n-1][m-1];
    }
};