class Solution {
    private:
    int func(int n){
        string s=to_string(n);
        reverse(s.begin(),s.end());
        int ans=stoi(s);
        return ans;
    }
public:
    int countNicePairs(vector<int>& nums) {
        int cnt=0;
        int mod=(int)(1e9+7);
        // for(int i=0;i<nums.size();i++){
        //     for(int j=0;j<nums.size();j++){
        //         if(i!=j){
        //             int a=func(nums[j]);
        //             int b=func(nums[i]);
        //             if(a+nums[i]==b+nums[j])
        //                 cnt++;
        //         }
        //     }
        // }return cnt/2;
        unordered_map<int,int>freq;
        for(int i=0;i<nums.size();i++){
            int num=func(nums[i]);
            int diff=nums[i]-num;
            cnt=(cnt+freq[diff])%mod;
            freq[diff]++;
        }return cnt%mod;
    }
};