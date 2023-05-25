//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
  int func(int ind,int target,vector<int>& arr,vector<vector<int>>&dp){
	    
	    if(ind==0) {
	        if(target==0 && arr[ind]==0) return 2;
	        if(target==0 || target==arr[0]) return 1;
	        else
	        return 0;
	    }
	    if(dp[ind][target]!=-1) return dp[ind][target];
	    int take=0;
	    if(arr[ind]<=target)
	    take=func(ind-1,target-arr[ind],arr,dp);
	    int notTake=func(ind-1,target,arr,dp);
	    return dp[ind][target]=(take + notTake);
	}
	int perfectSum(vector<int>& arr, int n, int sum)
	{
	    vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return func(n-1,sum,arr,dp);
	}
    int countPartitions(int n, int d, vector<int>& arr) {
        int t_sum=0;
        for(auto it:arr) t_sum+=it;
        if((t_sum-d)<0 || (t_sum-d)%2 ) return 0;
        return  perfectSum(arr,n,(t_sum-d)/2);
    }
    int findTargetSumWays(vector<int>&A ,int target) {
        return countPartitions(A.size(),target,A);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends