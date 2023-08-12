class Solution {
public:
    void func(int ind,int target,vector<int>&v,vector<vector<int>>&ans,vector<int>&nums){
        if(ind==-1){
            if(target==0){
                ans.push_back(v);
            }return;
        }
        //pick
        v.push_back(nums[ind]);
        if(target>=nums[ind])
        func(ind,target-nums[ind],v,ans,nums);
        v.pop_back();
        func(ind-1,target,v,ans,nums);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>v;
        vector<vector<int>>ans;
        func(n-1,target,v,ans,nums);
        return ans;
    }
};