class Solution {
public:

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        map<int,int>mp;
        
        int cnt=0;
        int sum=0;
        mp[0]=1;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
            // if(sum==goal){ cnt++;
            //          }
            // int rem=sum-goal;
            // if(mp.find(rem)!=mp.end()){
            //     cnt=cnt+mp[rem];
            //     mp[sum]++;
            // }else
            // mp[sum]++;
            int rem=sum-goal;
            cnt=cnt+mp[rem];
            mp[sum]++;
        }return cnt;
    }
};