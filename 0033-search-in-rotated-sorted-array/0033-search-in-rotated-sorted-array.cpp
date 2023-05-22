class Solution {
public:
    int search(vector<int>& nums, int target) {
      int i=0;
      int j=nums.size()-1;
      while(i<=j){
          int mid=(i+j)/2;
          if(nums[mid]==target)
          return mid;
          //left half is sorted 
            if(nums[i]<=nums[mid]){
                //target in left half
                if(nums[i]<=target && target<=nums[mid])
                j=mid-1;
                //target in right half
                else
                i=mid+1;
            }//right half is sorted
            else{
                //target in right half
                if(nums[mid]<=target && target<=nums[j])
                i=mid+1;
                //target in left half
                else
                j=mid-1;
            }
      }return -1;
    }
  };
