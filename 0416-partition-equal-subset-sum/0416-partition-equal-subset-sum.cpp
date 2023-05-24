class Solution {
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        vector<bool>prev(sum+1,0),curr(sum+1,0);
       prev[0]=curr[0]=true;
        if(arr[0]<=sum)
		prev[arr[0]]=true;
         for(int ind=1;ind<n;ind++){
             for(int target=1;target<=sum;target++){
                   bool take=false;
                    if(arr[ind]<=target)
                  take=prev[target-arr[ind]];
            bool nottake=prev[target];
            curr[target]=take | nottake;
             }prev=curr;
         }return prev[sum];
    }
    bool canPartition(vector<int>& nums) {
       int total_sum=0;
        for(int i=0;i<nums.size();i++)
            total_sum+=nums[i];
        if(total_sum%2==1) return false;
        int sum=total_sum/2;
        return isSubsetSum(nums,sum);
    }
};