class Solution {
public:
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int j=0;j<m;j++)
            dp[0][j]=matrix[0][j];
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int up=matrix[i][j]+dp[i-1][j];
                int diag1=0,diag2=0;
                if(j>=1)
                    diag1=matrix[i][j]+dp[i-1][j-1];
                else
                    diag1=1e9;
                if(j+1<m)
                     diag2=matrix[i][j]+dp[i-1][j+1];
                else
                    diag2=1e9;
                dp[i][j]=min(up,min(diag1,diag2));
            }
        }
        int mini=1e9;
        for(int j=0;j<m;j++){
            mini=min(mini,dp[n-1][j]);
        }return mini;
    }
};