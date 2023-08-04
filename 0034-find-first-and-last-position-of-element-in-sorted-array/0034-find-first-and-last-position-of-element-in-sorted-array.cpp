class Solution {
public:
    int firstoccurence(int n,int target,vector<int>&nums){
        int low=0;
        int high=n-1;
        int first=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                first=mid;
                high=mid-1;
            }
            else if(nums[mid]>target)
                high=mid-1;
            else 
                low=mid+1;
        }return first;
    }
     int lastoccurence(int n,int target,vector<int>&nums){
        int low=0;
        int high=n-1;
        int last=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                last=mid;
                low=mid+1;
            }
            else if(nums[mid]>target)
                high=mid-1;
            else 
                low=mid+1;
        }return last;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int first=firstoccurence(n,target,nums);
       
        int last=lastoccurence(n,target,nums);
         if(first==-1) return {-1,-1};
        return {first,last};
    }
};