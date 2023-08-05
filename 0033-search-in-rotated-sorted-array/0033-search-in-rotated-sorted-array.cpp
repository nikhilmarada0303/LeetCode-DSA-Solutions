class Solution {
public:
    int search(vector<int>& arr, int k) {
        int n=arr.size();
        int rotate=0;
    for(int i=1;i<n;i++){
        if(arr[i-1]>arr[i]){
            rotate=i;
            break;}

    }

    reverse(arr.begin(),arr.begin()+rotate);
    reverse(arr.begin()+rotate,arr.end());
    reverse(arr.begin(),arr.end());

    int low=0;
    int high=n-1;                           
    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==k) return (mid+rotate)%n;
        else if(arr[mid]>k)
            high=mid-1;
        else 
            low=mid+1;
    }
    
    return ans;
    }
};