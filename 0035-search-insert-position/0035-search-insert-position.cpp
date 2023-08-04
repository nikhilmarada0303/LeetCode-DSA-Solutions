class Solution {
public:
    int searchInsert(vector<int>& arr, int m) {
        int low=0;
	long high=arr.size()-1;
	long mid;
	while(low<=high){
		mid=low+(high-low)/2;
		if(arr[mid]==m) return mid;
		if(arr[mid]<m)
			low=mid+1;
		else
			high=mid-1;

	}return low;
    }
};