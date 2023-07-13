/*class Solution {
    private:
    int func(int ind,int prev_ind,vector<int>&nums,int n,vector<vector<int>>&dp){
        if(ind==n) return 0;
        if(dp[ind][prev_ind+1]!=-1) return dp[ind][prev_ind+1];
        int take=0;
        if(prev_ind==-1 || nums[ind]>nums[prev_ind])
            take=1+func(ind+1,ind,nums,n,dp);
        int nottake=func(ind+1,prev_ind,nums,n,dp);
        return dp[ind][prev_ind+1]=max(take,nottake);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return func(0,-1,nums,n,dp);
    }
};
*/


class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n=a.size();
         vector<int>dp(n,1);
       int maxi=1;
       for(int i=0;i<n;i++){
           for(int prev=0;prev<i;prev++){
               if(a[prev]<a[i])
                dp[i]=max(dp[i],1+dp[prev]);
           }maxi=max(maxi,dp[i]);
       }return maxi;
    }
};