class Solution {
public:
    int minDistance(string s, string t) {
         int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=m;i++)
        dp[0][i]=i;
         for(int i=0;i<=n;i++)
        dp[i][0]=i;
        
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){
                 if(s[ind1-1]==t[ind2-1])
                     dp[ind1][ind2]=dp[ind1-1][ind2-1];
                else
                 dp[ind1][ind2]=1+min(dp[ind1][ind2-1],
                    min(dp[ind1-1][ind2],dp[ind1-1][ind2-1]));
            }
        }
        
        return dp[n][m];
    }
};