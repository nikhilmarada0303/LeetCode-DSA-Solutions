class Solution {
public:
    bool search(vector<int>& arr, int k) {
        int n=arr.size();
         int low=0;
   int high=n-1;
   while(low<=high){
       int mid=(low+high)/2;
       if(arr[mid]==k) return 1;
       
       if(arr[low]==arr[mid] && arr[mid]==arr[high]){     
           low=low+1;
           high=high-1;   
           continue;
       }
       
       if(arr[low]<=arr[mid]){           //left part is sorted
           if(arr[low]<=k && k<=arr[mid]){
               high=mid-1;             //element exists
           }
           else
            low=mid+1;
       }else{                                    // right part is sorted
            if(arr[mid]<=k && k<=arr[high]){
                low=mid+1;                    //element exists
            }
            else 
                high=mid-1;
       }
   }return 0;
    }
};