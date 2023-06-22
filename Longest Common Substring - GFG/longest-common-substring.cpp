//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
     int func(int ind1,int ind2,string &s1,string &s2,int &ans,vector<vector<int>>&dp){
          if(ind1<0 || ind2<0) return 0;
        int match=0;
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(s1[ind1]==s2[ind2]){
             match=1+func(ind1-1,ind2-1,s1,s2,ans,dp);
                 ans=max(ans,match);
        }
           int a= func(ind1-1,ind2,s1,s2,ans,dp);
            int b=func(ind1,ind2-1,s1,s2,ans,dp);
        return dp[ind1][ind2]=match;
    }
    int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        int ans=0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        func(n-1,m-1,s1,s2,ans,dp);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends