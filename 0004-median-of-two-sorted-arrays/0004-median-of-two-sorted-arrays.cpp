class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        vector<int>ans;

	int i=0; int j=0;
	int n=a.size(); int m=b.size();

	while(i<n && j<m){
		if(a[i]<=b[j]){
			ans.push_back(a[i]);
			i++;
		}else{
			ans.push_back(b[j]);
			j++;
		}
	}
	while(i<n){
		ans.push_back(a[i]);
		i++;
	}
	while(j<m){
		ans.push_back(b[j]);
		j++;
	}
	if((n+m)%2==0){
		int mid=(n+m)/2;
		double x=(double)(ans[mid]+ans[mid-1])/2;
		return x;
	}else {
		int mid=(n+m)/2;
		return ans[mid];
	}return -1;
    }
};