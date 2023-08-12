class Solution {
public:
    void func(int ind,vector<int>&nums,vector<int>v,vector<vector<int>>&ans,int n){
        if(ind==-1){
            ans.push_back(v);
            return;
        }
        func(ind-1,nums,v,ans,n);
        v.push_back(nums[ind]);
        func(ind-1,nums,v,ans,n);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>v;
        vector<vector<int>>ans;
        int n=nums.size();
        func(n-1,nums,v,ans,n);
        return ans;
        
    }
};