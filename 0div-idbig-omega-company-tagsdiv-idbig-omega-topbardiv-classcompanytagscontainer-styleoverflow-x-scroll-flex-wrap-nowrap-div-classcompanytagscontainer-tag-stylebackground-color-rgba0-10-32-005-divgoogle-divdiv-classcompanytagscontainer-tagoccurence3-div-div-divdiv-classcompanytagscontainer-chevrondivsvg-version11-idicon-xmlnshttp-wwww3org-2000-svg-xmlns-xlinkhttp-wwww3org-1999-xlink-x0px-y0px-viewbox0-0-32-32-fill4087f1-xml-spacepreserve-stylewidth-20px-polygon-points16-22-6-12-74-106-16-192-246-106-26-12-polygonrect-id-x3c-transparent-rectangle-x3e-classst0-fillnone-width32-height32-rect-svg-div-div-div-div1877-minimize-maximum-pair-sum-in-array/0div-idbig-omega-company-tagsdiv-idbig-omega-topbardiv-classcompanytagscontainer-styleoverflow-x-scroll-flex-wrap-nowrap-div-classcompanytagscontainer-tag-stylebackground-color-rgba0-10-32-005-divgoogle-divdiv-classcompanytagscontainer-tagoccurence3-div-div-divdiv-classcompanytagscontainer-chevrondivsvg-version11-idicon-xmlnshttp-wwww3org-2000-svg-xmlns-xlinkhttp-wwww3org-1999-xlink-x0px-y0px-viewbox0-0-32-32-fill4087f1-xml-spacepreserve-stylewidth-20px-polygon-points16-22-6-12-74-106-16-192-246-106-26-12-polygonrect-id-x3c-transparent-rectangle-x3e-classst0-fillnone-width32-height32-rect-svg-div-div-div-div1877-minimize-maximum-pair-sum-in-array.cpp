class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<pair<int,int>>v;
        int n=nums.size();
        
        for(int i=0;i<n/2;i++){
            v.push_back({nums[i],nums[n-i-1]});
        }
        int m=INT_MIN;
        
        for(int i=0;i<n/2;i++){
            int sum=v[i].first+v[i].second;
            m=max(m,sum);
        }return m;
    }
};