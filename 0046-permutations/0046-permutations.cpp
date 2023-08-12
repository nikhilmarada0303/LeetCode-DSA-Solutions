class Solution {
public:
    void func(vector<int>&ds,vector<int>&vis,vector<vector<int>>&ans,vector<int>&nums){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!vis[i]){
                vis[i]=1;
                ds.push_back(nums[i]);
                func(ds,vis,ans,nums);
                vis[i]=0;
                ds.pop_back();
            }
        }return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>vis(nums.size(),0);
        vector<int>ds;
        vector<vector<int>>ans;
        func(ds,vis,ans,nums);
        return ans;
    }
};