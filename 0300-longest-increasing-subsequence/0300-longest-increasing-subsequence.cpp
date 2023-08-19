class Solution {
public:
    int func(int ind,int prev_ind,vector<int>&nums,int n,vector<vector<int>>&dp){
        if(ind==n){
            // if(nums[ind-1]<=nums[ind])
            // return 1;
            // return 0;
            return 0;
        }if(dp[ind][prev_ind+1]!=-1) return dp[ind][prev_ind+1];
        int take=0;
        if(prev_ind==-1 || nums[prev_ind]<nums[ind])
           take=1+func(ind+1,ind,nums,n,dp);
        int not_take=func(ind+1,prev_ind,nums,n,dp);
        return dp[ind][prev_ind+1]=max(take,not_take);
    }
    int lengthOfLIS(vector<int>&nums) {
        int n=nums.size();
        vector<int>ahead(n+1,0);
        vector<int>curr(n+1,0);
       for(int ind=n-1;ind>=0;ind--){
           for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--){
               int take=0;
                if(prev_ind==-1 || nums[prev_ind]<nums[ind])
                 take=1+ahead[ind+1];
                int not_take=ahead[prev_ind+1];
                 curr[prev_ind+1]=max(take,not_take);
           }ahead=curr;
       }return curr[-1+1];
    }
};