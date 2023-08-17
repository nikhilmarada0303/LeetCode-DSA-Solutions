class Solution {
public:
    int func(int row,int col,vector<vector<int>>&dp){
        if(row==0 && col==0) return 1;
        if(row<0 || col<0) return 0;
        if(dp[row][col]!=-1) return dp[row][col];
        
        int left=func(row,col-1,dp);
        int right=func(row-1,col,dp);
        return dp[row][col]=left+right;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,0));
        dp[0][0]=1;
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(row==0 && col==0) continue;
                int left=0;int right=0;
                if(col>0)
                left=dp[row][col-1];
                if(row>0)
                 right=dp[row-1][col];
                dp[row][col]=left+right;
            }
        }return dp[m-1][n-1];
    }
};