class Solution {
public:
    int findMin(vector<int>& arr) {
        int n=arr.size();
	int rotate=1;
	for(int i=1;i<n;i++){
		if(arr[i-1]>arr[i])
			break;
		rotate++;
	}
	reverse(arr.begin(),arr.begin()+rotate);
	reverse(arr.begin()+rotate,arr.end());
	reverse(arr.begin(),arr.end());

	return arr[0];
    }
};