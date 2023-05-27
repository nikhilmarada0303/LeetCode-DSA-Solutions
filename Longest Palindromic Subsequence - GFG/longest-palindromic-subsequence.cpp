//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int lcs(int x, int y, string s1, string s2)
    {
        vector<vector<int>>dp(x+1,vector<int>(y+1,0));
        for(int i=0;i<=x;i++)
            dp[i][0]=0;
        for(int i=0;i<=y;i++)
            dp[0][i]=0;
        for(int ind1=1;ind1<=x;ind1++){
            for(int ind2=1;ind2<=y;ind2++){                                         
                 if(s1[ind1-1]==s2[ind2-1])
                    dp[ind1][ind2]= 1+dp[ind1-1][ind2-1];
                else{
                dp[ind1][ind2]=max(dp[ind1-1][ind2],dp[ind1][ind2-1]);}
                 
            }
        }return dp[x][y];
      
    }
    int longestPalinSubseq(string s1) {
        string s2=s1;
        reverse(s2.begin(),s2.end());
        return lcs(s1.size(),s1.size(),s1,s2);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends