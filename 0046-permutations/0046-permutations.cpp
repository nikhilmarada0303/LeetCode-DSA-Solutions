class Solution {
public:
    void func(int ind,vector<vector<int>>&ans,vector<int>&nums){
        if(ind==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            swap(nums[i],nums[ind]);
            func(ind+1,ans,nums);
            swap(nums[ind],nums[i]);
        }return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        func(0,ans,nums);
        return ans;
    }
};