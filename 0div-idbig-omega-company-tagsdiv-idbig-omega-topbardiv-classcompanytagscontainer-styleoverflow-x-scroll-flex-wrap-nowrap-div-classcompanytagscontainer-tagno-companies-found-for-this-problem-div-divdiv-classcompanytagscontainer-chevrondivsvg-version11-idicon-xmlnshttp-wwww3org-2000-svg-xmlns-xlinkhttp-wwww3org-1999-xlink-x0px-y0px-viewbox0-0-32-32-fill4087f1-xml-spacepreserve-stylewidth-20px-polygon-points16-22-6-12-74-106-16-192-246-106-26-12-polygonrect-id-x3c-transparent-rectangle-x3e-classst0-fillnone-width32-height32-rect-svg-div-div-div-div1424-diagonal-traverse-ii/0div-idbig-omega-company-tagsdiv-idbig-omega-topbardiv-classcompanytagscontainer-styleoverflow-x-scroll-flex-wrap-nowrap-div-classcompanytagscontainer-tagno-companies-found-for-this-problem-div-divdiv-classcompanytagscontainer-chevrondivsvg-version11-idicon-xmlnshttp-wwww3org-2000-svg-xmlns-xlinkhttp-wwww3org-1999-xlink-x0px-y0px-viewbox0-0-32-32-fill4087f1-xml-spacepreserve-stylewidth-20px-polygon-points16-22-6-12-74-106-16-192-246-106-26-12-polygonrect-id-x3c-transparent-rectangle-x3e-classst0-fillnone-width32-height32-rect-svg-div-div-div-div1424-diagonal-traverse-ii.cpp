class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n=nums.size();
        map<int,vector<int>>mp;             // (i+j)---->{elements}
        
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<nums[i].size();j++){
                mp[i+j].push_back(nums[i][j]);
            }
        }
        vector<int>v;
        for(auto it:mp){
            for(auto it1:it.second){
                v.push_back(it1);
            }
        }return v;
    }
};