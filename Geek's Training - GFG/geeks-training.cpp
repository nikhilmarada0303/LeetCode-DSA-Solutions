//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int func(int ind,int last,vector<vector<int>>&points,vector<vector<int>>&dp){
      if(ind==0){
          int maxi=0;
          for(int task=0;task<3;task++){
              if(task!=last)
              maxi=max(maxi,points[0][task]);
          }return maxi;
      }if(dp[ind][last]!=-1) return dp[ind][last];
      int maxi=0;
      for(int task=0;task<3;task++){
          if(task!=last){
              int point_s=points[ind][task]+func(ind-1,task,points,dp);
              maxi=max(maxi,point_s);
          }
      }return dp[ind][last]=maxi;
  }
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        vector<vector<int>>dp(n,vector<int>(4,-1));
        return func(n-1,3,points,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends