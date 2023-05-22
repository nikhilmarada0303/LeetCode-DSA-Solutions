//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    int func(vector<int>&dp,vector<int>&h,int ind){
        if(ind ==0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int left=func(dp,h,ind-1)+abs(h[ind]-h[ind-1]);
        int right=INT_MAX;
        if(ind>1)
        right=func(dp,h,ind-2)+abs(h[ind]-h[ind-2]);
        return dp[ind]=((left>right)?right:left);
    }
    int minimumEnergy(vector<int>& h, int n) {
	  vector<int>dp(n+1,-1);
        return func(dp,h,n-1);
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