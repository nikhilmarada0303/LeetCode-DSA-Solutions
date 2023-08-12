class Solution {
public:
     void func(vector<int>&ds,vector<int>&vis,set<vector<int>>&st,vector<int>&nums){
        if(ds.size()==nums.size()){
            st.insert(ds);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!vis[i]){
                vis[i]=1;
                ds.push_back(nums[i]);
                func(ds,vis,st,nums);
                vis[i]=0;
                ds.pop_back();
            }
        }return;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int>vis(nums.size(),0);
        vector<int>ds;
        set<vector<int>>st;
        func(ds,vis,st,nums);
        
        vector<vector<int>>ans;
        for(auto it:st)
            ans.push_back(it);
        return ans;
    }
};