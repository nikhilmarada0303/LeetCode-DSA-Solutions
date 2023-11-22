class Solution {
private:
    bool func(int posi, int dest, vector<int> nums,vector<int>&dp) {
        if (posi >=dest) return true;
        if (nums[posi] == 0) return false;
        
        if(dp[posi]!=-1) return dp[posi];
        int max_jump=nums[posi];
        for(int i=1;i<=max_jump;i++){
            if (func(posi+i, dest, nums,dp)) 
                return dp[posi]=true;
        }
        return dp[posi]=false;
    }

public:
    bool canJump(vector<int>& nums) {
        int dest = nums.size() - 1;
        
        vector<int>dp(dest+1,0);
        dp[dest]=1;
        for(int ind=dest;ind>=0;ind--){
            for(int j=0;j<=nums[ind]&&ind+j<=dest;j++){
                if(dp[ind+j]){
                    dp[ind]=true;
                    break;
                }
            }
        }return dp[0];
        
        return func(0,dest,nums,dp);
    }
};
