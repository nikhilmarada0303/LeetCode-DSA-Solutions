//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
     int func(int ind,int W,int wt[],int val[],vector<vector<int>>&dp){
        if(ind==0 ){
          return (int)(W/wt[0])*val[0];
        }
         if(dp[ind][W]!=-1) return dp[ind][W];
        int notTake=0+func(ind-1,W,wt,val,dp);
        int take=INT_MIN;
        if(wt[ind]<=W)
        take=val[ind]+func(ind,W-wt[ind],wt,val,dp);
        return dp[ind][W]=max(take,notTake);
    }
    int knapSack(int n,int W,int val[], int wt[] ) 
    { 
        vector<vector<int>>dp(n,vector<int>(W+1,0));
        for(int weight=0;weight<=W;weight++)
        dp[0][weight]=(int)(weight/wt[0])*val[0];
        for(int ind=1;ind<n;ind++){
           for(int W1=0;W1<=W;W1++){
                int notTake=0+dp[ind-1][W1];
                int take=INT_MIN;
                if(wt[ind]<=W1)
                take=val[ind]+dp[ind][W1-wt[ind]];
                dp[ind][W1]=max(take,notTake);
           }
       }return dp[n-1][W];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends