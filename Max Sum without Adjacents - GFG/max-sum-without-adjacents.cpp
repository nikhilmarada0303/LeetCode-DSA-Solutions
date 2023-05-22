//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findMaxSum(int *arr, int n) {
	    // code here
	   vector<int>dp(n+1,-1);
	dp[0]=arr[0];
	int pick;
	   for(int i=1;i<n;i++){
	       if(i>1)
	       pick=arr[i]+dp[i-2];
	       else
	       pick=arr[i];
	       int not_pick=0+dp[i-1];
	       dp[i]=max(pick,not_pick);
	   }
	return dp[n-1];
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends