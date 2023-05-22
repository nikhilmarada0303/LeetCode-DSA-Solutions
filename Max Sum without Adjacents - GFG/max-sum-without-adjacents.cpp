//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findMaxSum(int *arr, int n) {
	int pick;
	int prev2=0;
	int prev=arr[0];
	   for(int i=1;i<n;i++){
	       if(i>1)
	       pick=arr[i]+prev2;
	       else
	       pick=arr[i];
	       int not_pick=0+prev;
	       int curr=max(pick,not_pick);
	       
	       prev2=prev;
	       prev=curr;
	   }
	return prev;
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