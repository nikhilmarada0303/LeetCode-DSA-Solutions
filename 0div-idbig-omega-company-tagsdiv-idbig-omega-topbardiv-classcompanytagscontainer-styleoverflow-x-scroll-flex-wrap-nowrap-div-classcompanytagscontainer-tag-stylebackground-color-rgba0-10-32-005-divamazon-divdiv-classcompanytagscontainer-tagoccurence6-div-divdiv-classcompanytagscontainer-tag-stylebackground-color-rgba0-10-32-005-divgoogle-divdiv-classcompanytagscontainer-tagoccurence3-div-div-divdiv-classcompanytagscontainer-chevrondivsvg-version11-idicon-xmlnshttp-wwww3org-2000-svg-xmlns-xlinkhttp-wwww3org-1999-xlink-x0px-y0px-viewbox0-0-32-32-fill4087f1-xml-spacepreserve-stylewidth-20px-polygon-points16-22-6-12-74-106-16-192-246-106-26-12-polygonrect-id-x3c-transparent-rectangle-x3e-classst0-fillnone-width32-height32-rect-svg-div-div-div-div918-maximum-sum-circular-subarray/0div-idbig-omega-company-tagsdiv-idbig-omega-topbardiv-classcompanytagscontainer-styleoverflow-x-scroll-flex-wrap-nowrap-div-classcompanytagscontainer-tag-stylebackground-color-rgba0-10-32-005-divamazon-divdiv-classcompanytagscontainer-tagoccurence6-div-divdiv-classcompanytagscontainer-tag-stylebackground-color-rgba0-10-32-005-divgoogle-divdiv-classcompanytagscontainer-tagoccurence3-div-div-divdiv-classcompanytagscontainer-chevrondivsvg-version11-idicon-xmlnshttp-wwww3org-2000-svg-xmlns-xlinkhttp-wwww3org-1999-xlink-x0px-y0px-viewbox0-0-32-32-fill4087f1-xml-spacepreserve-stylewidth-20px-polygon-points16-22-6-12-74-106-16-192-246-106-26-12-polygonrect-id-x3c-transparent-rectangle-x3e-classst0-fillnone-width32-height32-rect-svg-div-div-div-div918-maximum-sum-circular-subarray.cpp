class Solution {
    
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int maxiSum=INT_MIN;
        int sum=0;
        for(int i=0;i<n;i++){                   //case1
            if(sum<0) sum=0;
            sum=sum+nums[i];
            maxiSum=max(maxiSum,sum);
        }
        int miniSum=INT_MAX;
        sum=0;
        for(int i=0;i<n;i++){
            if(sum>0) sum=0;
            sum=sum+nums[i];
            miniSum=min(miniSum,sum);
        }
        int Tsum=accumulate(nums.begin(),nums.end(),0);
        int cSum=Tsum-miniSum;                     //case 2
        if(maxiSum>0) return max(cSum,maxiSum);
        return maxiSum;
    }
};