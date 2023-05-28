class Solution{
public:
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<double>>dp(n+1,vector<double>(m+1,0));
        for(int i=0;i<=n;i++) dp[i][0]=1;
        for(int j=1;j<=m;j++) dp[0][j]=0;
        
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){
                 if(s[ind1-1]==t[ind2-1])
                  dp[ind1][ind2]=dp[ind1-1][ind2-1]+dp[ind1-1][ind2];
                else
                 dp[ind1][ind2]=dp[ind1-1][ind2];
            }
        }return (int)dp[n][m];
    }
};