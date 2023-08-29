class Solution {
public:
    int func(int ind,int d,vector<int>&nums,vector<vector<int>>&dp){
        if(d==0 && ind==nums.size()){
            if(d==0) return 0;
            return 1e9;
        }if(d<0) return 1e9;
        long maxi=INT_MIN; long ans=INT_MAX;
         if(dp[ind][d]!=-1) return dp[ind][d];
        for(int i=ind;i<nums.size();i++){
            if(nums[i]>maxi)
                maxi=nums[i];
            long temp=maxi+func(i+1,d-1,nums,dp);
            ans=min(ans,temp);
        }return dp[ind][d]=ans;
    }
    int minDifficulty(vector<int>& nums, int d) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(d+1,-1));
        int ans=func(0,d,nums,dp);
        if(ans>1e9)
            return -1;
        return ans;
    }
};