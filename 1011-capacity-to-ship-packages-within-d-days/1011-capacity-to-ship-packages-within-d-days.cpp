class Solution {
public:
    int func(vector<int>&arr,int cap){
    int load=0;
    int days=1;
    for(int i=0;i<arr.size();i++){
        if(load+arr[i]>cap){
            days++;
            load=arr[i];
        }
        else{
            load+=arr[i];
        }
    }return days;
}
    int shipWithinDays(vector<int>& weights, int d) {
         int sum=0;
    int maxi=INT_MIN;
    for(int i=0;i<weights.size();i++){
        sum+=weights[i];
        maxi=max(maxi,weights[i]);
    }
    int ans=-1;
    int low=maxi;
    int high=sum;
    while(low<=high){
        int mid=(low+high)/2;
        int reqDays=func(weights,mid);
        if(reqDays<=d){
            ans=mid;
            high=mid-1;
        }else low=mid+1;
    }
    return ans;
    }
};