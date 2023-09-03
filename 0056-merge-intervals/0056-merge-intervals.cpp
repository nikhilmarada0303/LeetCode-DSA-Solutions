class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(ans.empty() || ans.back()[1]<nums[i][0]) 
                ans.push_back(nums[i]);
            
            else if(ans.back()[1]>=nums[i][0])
                ans.back()[1]=max(ans.back()[1],nums[i][1]);
        }return ans;
    }
};