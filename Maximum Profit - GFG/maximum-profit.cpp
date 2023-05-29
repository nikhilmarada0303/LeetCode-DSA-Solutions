//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int func(int ind,int transaction,int price[],int n,int k,vector<vector<int>>&dp){
    if(transaction==2*k) return 0;
    if(ind==n) return 0;
    int profit=0;
    if(dp[ind][transaction]!=-1) return dp[ind][transaction];
    if(transaction%2==0){
        profit=max(-price[ind]+func(ind+1,transaction+1,price,n,k,dp),func(ind+1,transaction,price,n,k,dp));
    }else
        profit=max(price[ind]+func(ind+1,transaction+1,price,n,k,dp),func(ind+1,transaction,price,n,k,dp));
        return dp[ind][transaction]=profit;
}

    int maxProfit(int k, int n, int price[]) {
        vector<vector<int>>dp(n,vector<int>(2*k,-1));
        return func(0,0,price,n,k,dp);
    
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends