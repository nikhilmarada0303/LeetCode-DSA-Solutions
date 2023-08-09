class Solution {
public:
    bool check(vector<int>&nums,int num,int p){
        int cnt=0;
        int i=0;
        
        while(i<nums.size()-1){
            if(abs(nums[i]-nums[i+1])<=num) {
                cnt++;
                i=i+2;
            }else i++;
        }
        if(cnt>=p) return true;
        return false;
    }
    int minimizeMax(vector<int>& nums, int p) {                //min(max)
        sort(nums.begin(),nums.end());
        int low=0;
        int high=nums[nums.size()-1]-nums[0];
        int ans=-1;
        
        while(low<=high){
            int mid=(low+high)/2;
            
            if(check(nums,mid,p)){
                ans=mid;
                high=mid-1;
            }else low=mid+1;
        }
        return ans;
    }
};