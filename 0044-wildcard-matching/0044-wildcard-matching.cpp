class Solution {
public:
    bool isMatch(string str, string pat) {
        int n=pat.size();
        int m=str.size();
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
        dp[0][0]=true;
        for(int j=1;j<=m;j++)
            dp[0][j]=false;
        for(int i=1;i<=n;i++){
            bool flag=true;
            for(int ii=1;ii<=i;ii++){
                if(pat[ii-1]!='*'){
                    flag=false;break;}
            }dp[i][0]=flag;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(pat[i-1]==str[j-1] || pat[i-1]=='?')
                     dp[i][j]=dp[i-1][j-1];
                else if(pat[i-1]=='*')
                     dp[i][j]=(dp[i-1][j] | dp[i][j-1]);
                else
                     dp[i][j]=false;
            }
        }return dp[n][m];
        
    }
};