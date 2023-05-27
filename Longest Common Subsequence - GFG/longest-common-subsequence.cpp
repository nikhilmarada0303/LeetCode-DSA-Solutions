//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    int func(int ind1,int ind2,string &s1,string &s2,vector<vector<int>>&dp){
        if(ind1<0 || ind2<0) return 0;
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        int match=INT_MIN;
        
        if(s1[ind1]==s2[ind2])
            match= 1+func(ind1-1,ind2-1,s1,s2,dp);
        
        int not_match= 0+max(func(ind1-1,ind2,s1,s2,dp),func(ind1,ind2-1,s1,s2,dp));
        return dp[ind1][ind2]=max(match,not_match);
    }
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
};


//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends