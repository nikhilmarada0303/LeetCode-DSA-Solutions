class Solution {
public:
    
int sumDivisor(vector<int>&arr,int number){
	int sum=0;
	for(int i=0;i<arr.size();i++){
		int d=ceil((double)arr[i]/(double)number);
		sum+=d;
	}return sum;
}

    int smallestDivisor(vector<int>& arr, int limit) {
      sort(arr.begin(),arr.end());
	int n=arr.size();
	int low=1;
	int high=arr[n-1];
	int ans=-1;
	while(low<=high){
		int mid=(low+high)/2;
		int SumDivisor=sumDivisor(arr,mid);
		if(SumDivisor<=limit){
			ans=mid;
			high=mid-1;
		}
		else low=mid+1;
	}return ans;
    }
};