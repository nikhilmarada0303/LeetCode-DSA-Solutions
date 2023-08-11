class Solution {
public:
    int func(int ind,int c,vector<int>& coins,vector<vector<int>>&dp){
        if(ind==0) return c%coins[ind]==0;
        int pick=0;
        if(dp[ind][c]!=-1) return dp[ind][c];
        if(c>=coins[ind])
        pick=func(ind,c-coins[ind],coins,dp);
        int not_pick=func(ind-1,c,coins,dp);
        return dp[ind][c]=pick+not_pick;
    }
    int change(int sum, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(sum+1,-1));
       return func(coins.size()-1,sum,coins,dp);
    }
};