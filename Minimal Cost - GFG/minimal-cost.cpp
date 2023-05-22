//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int F(vector<int>&height,int ind,int k,vector<int>&dp){
      if(ind==0)
      return 0;
      int min_steps=INT_MAX;
      int jumps=INT_MAX;
	if(dp[ind]!=-1) return dp[ind];
      for(int i=1;i<=k;i++){
          if(ind>=i)
          jumps=F(height,ind-i,k,dp)+abs(height[ind]-height[ind-i]);
        	min_steps=min(min_steps,jumps);
      }return dp[ind]=min_steps;
  }
    int minimizeCost(vector<int>& height, int n, int k) {
        vector<int>dp(n+1,-1);
        return F(height,n-1,k,dp);
    
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends