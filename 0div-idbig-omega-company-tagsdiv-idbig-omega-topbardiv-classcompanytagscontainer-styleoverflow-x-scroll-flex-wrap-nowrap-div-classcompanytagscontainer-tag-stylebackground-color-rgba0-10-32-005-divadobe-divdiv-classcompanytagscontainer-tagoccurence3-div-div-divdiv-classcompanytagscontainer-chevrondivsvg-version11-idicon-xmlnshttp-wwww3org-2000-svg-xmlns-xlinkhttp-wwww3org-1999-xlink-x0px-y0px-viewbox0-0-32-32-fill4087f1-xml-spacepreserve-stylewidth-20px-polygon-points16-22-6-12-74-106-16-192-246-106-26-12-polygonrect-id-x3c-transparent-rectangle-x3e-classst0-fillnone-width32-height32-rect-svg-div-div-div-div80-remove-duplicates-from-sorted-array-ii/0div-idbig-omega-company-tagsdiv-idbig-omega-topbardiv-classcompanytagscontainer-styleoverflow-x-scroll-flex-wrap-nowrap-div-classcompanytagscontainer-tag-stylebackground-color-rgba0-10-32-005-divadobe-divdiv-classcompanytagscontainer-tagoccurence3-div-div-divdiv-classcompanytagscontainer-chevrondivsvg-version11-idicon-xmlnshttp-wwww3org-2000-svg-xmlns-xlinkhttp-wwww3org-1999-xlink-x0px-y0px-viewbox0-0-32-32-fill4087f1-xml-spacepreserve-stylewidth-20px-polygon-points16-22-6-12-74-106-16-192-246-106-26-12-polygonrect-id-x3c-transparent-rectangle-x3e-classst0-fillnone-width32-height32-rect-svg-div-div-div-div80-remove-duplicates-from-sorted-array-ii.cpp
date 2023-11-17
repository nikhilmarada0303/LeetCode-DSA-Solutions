class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int>mp;
        for(auto it:nums)
            mp[it]++;
        vector<int>v;
        for(auto it:mp){
            if(it.second>=2){
                v.push_back(it.first);
                v.push_back(it.first);
            }
            else if(it.second==1)
                v.push_back(it.first);
        
        }
        for(int i=0;i<v.size();i++)
            nums[i]=v[i];
        return v.size();
    }
};