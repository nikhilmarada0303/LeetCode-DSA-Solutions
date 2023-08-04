class Solution {
public:
      void func(int ind, vector<int>& nums, set<vector<int>>& st, vector<int>& ans, vector<int>& vis) {
        if (ind == nums.size()) {
            st.insert(ans); 
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!vis[i]) {
                vis[i] = 1;
                ans.push_back(nums[i]);
                func(ind + 1, nums, st, ans, vis);
                ans.pop_back(); 
                vis[i] = 0;
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
       set<vector<int>> st;
        vector<int> vis(nums.size(), 0);
        vector<int> ans;
        func(0, nums, st, ans, vis);
        vector<vector<int>> f;
        for (const auto& it : st) {
            f.push_back(it);
        }

        return f;
    }
};