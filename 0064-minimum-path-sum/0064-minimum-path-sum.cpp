class Solution {
public:
    int func(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(i==0 && j==0 ) return grid[0][0];
        if(i<0 || j<0 ) return 1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        int left=0;
        int right=0;
         left=grid[i][j]+func(i,j-1,grid,dp);
         right=grid[i][j]+func(i-1,j,grid,dp);
        return dp[i][j]=min(left,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> prev(n,0);
        for(int i=0;i<m;i++){
             vector<int> curr(n,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0)  curr[0]=grid[0][0];
                else{
                    int left=0,right=0;
                    if(j>=1)
                   left=grid[i][j]+curr[j-1];
                    else 
                        left=1e9;
                    if(i>=1)
                    right=grid[i][j]+prev[j];
                    else
                        right=1e9;
                     curr[j]=min(left,right);
                }
            }prev=curr;
        }return prev[n-1];
      
    }
};