class Solution {
public:
    bool possible(vector<int>&arr,int k,int m,int groomday){
	int cnt=0;
	int boquets=0;
	for(int i=0;i<arr.size();i++){
		if(arr[i]<=groomday) cnt++;
		else{
			boquets+=cnt/k;
			cnt=0;
		}
	}boquets+=cnt/k;        //last case
	if(m<=boquets) return true;
	return false;
}

    int minDays(vector<int>& arr, int m, int k) {
        
    
    long long val=m* 1ll * k * 1ll;
    if(val>arr.size()) return -1;
	int maxi=INT_MIN;
	int mini=INT_MAX;

	for(int i=0;i<arr.size();i++){
		maxi=max(maxi,arr[i]);
		mini=min(mini,arr[i]);
	}
	long low=mini;
	long high=maxi;
	long ans=-1;

	while(low<=high){
		long long mid=(low+high)/2;
		if(possible(arr,k,m,mid)){
			ans=mid;
			high=mid-1;
		}
		else low=mid+1;
	}
	return ans;
    }
};