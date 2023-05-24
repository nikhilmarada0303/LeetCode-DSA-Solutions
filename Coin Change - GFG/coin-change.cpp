//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    long long int func(int ind,int coins[],int target,vector<vector<long>>&dp){
        if(ind==0){
           return (target%coins[ind]==0);
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        long long notTake=func(ind-1,coins,target,dp);
        long long take=0;
        if(coins[ind]<=target)
        take=func(ind,coins,target-coins[ind],dp);
        return dp[ind][target]=take+notTake;
        
    }
    long long int count(int coins[], int n, int sum) {
        vector<vector<long>>dp(n,vector<long>(sum+1,-1));
        return func(n-1,coins,sum,dp);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends