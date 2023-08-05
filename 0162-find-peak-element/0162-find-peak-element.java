class Solution {
    public int findPeakElement(int[] arr) {
     int n=arr.length;
//         if(n==1) return 0;
        
//         for(int i=0;i<n;i++){
//             if(i==0) {
//                 if(nums[i]>nums[i+1]) return 0;
//                 else 
//                     continue;
//             }
//             if(i==n-1){
//                 if(nums[i]>nums[i-1]) return n-1;
//                 else 
//                     continue;
//             }
//             if(nums[i-1]<nums[i] && nums[i+1]<nums[i]){
//                 return i;
//             }
//         }return -1;
        
         
    if(n==1) return 0;
    if(arr[0]>arr[1]) return 0;
    if(arr[n-1]>arr[n-2]) return n-1;
    int low=1;
    int high=n-2;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) return mid;
        else if(arr[mid]>arr[mid-1]) low=mid+1;
        else high=mid-1;
    }return -1;
    }
}