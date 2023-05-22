//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    
    int minimumEnergy(vector<int>& h, int n) {
	  vector<int>dp(n,-1);
        dp[0]=0;
        for(int i=1;i<n;i++){
            int left=dp[i-1]+abs(h[i]-h[i-1]);
            int right=INT_MAX;
            if(i>1)
            right=dp[i-2]+abs(h[i]-h[i-2]);
            dp[i]=((left>right)?right:left);
        }return dp[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends