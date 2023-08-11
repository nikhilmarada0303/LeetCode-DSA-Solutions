class Solution {
public:
    int func(int ind,int c,vector<int>& coins,vector<vector<int>>&dp){
        if(ind==0) return c%coins[ind]==0;
        if(dp[ind][c]!=-1) return dp[ind][c];
        int pick=0;
        if(c>=coins[ind])
        pick=func(ind,c-coins[ind],coins,dp);
        int not_pick=func(ind-1,c,coins,dp);
        return dp[ind][c]=pick+not_pick;
    }
    int change(int sum, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,0));
        
        for(int i=0;i<=sum;i++){
            dp[0][i]=(i%coins[0]==0);
        }
        
        for(int ind=1;ind<n;ind++){
            for(int c=0;c<=sum;c++){
                int pick=0;
                if(c>=coins[ind])
                pick=dp[ind][c-coins[ind]];
                int not_pick=dp[ind-1][c];
                 dp[ind][c]=pick+not_pick;
            }
        }return dp[n-1][sum];
    }
};