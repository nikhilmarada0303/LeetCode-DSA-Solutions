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
        vector<vector<int>>dp(n,vector<int>(m,0));
        // return func(grid.size()-1,grid[0].size()-1,grid,dp);
        
        dp[0][0]=1;
                int mod=(int)1e9+7;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) dp[i][j]=0;
                else if(i==0 && j==0) dp[i][j]=1;
                else{
                int left=0,right=0;
                if(i>=1)
                left=dp[i-1][j];
                if(j>=1)
                right=dp[i][j-1];
                dp[i][j]=(left+right);}
            }
        }return dp[n-1][m-1];
    }
};