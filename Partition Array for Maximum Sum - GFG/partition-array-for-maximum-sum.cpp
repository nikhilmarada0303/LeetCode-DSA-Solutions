//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private:
    int func(int i,int k,int n,vector<int>&arr,vector<int>&dp){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int max_ans=INT_MIN;
        int len=0;
        int max_element=INT_MIN;
        for(int j=i;j<min(n,i+k);j++){
            len++;
            max_element=max(max_element,arr[j]);
            int sum=(len*max_element)+func(j+1,k,n,arr,dp);
            max_ans=max(max_ans,sum);
        }return dp[i]=max_ans;
    }
    public:
    int solve(int n, int k, vector<int>& arr){
        vector<int>dp(n,-1);
        return func(0,k,n,arr,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            int x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        cout<<obj.solve(n,k,arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends