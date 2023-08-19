class Solution {
public:
    int func(int ind,int sum,vector<int>&coins,vector<vector<int>>&dp){
        if(ind==-1){
            if(sum==0){
                return 0;
            }return 1e9;
        }
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        int take=1e9;
        if(coins[ind]<=sum){
           take=1+func(ind,sum-coins[ind],coins,dp);
        }
        int not_take=func(ind-1,sum,coins,dp);
        return dp[ind][sum]=min(take,not_take);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=func(n-1,amount,coins,dp);
        return ans!=1e9?ans:-1;       
    }
};
