class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<32;i++){
            int count0=0;
             int count1=0;
            for(int j=0;j<nums.size();j++){
                if((1<<i) & nums[j])
                    count1++;
                else count0++;
            }
            ans=ans+(count0*count1);
        }return ans;
    }
};