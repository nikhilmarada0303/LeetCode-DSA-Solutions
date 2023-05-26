class Solution {
public:
    
    int func(int ind,int prev_ind,int n,vector<int>&a,vector<vector<int>>&dp){
        if(ind==n) return 0;
        int take=0;
        if(dp[ind][prev_ind+1]!=-1) return dp[ind][prev_ind+1];
        if(prev_ind==-1 || a[ind]>a[prev_ind])
            take=1+func(ind+1,ind,n,a,dp);
        int notTake=0+func(ind+1,prev_ind,n,a,dp);
        return dp[ind][prev_ind+1]=max(take,notTake);
    }
    
    int lengthOfLIS(vector<int>& nums) {
       int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
       return func(0,-1,n,nums,dp);
        
    }
};