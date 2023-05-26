//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int NumberofLIS(int n, vector<int>&arr) {
        int maxi=1;
        vector<int>dp(n,1),cnt(n,1);
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(arr[prev]<arr[i] && 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                    cnt[i]=cnt[prev];
                }else if(arr[prev]<arr[i] && 1+dp[prev]==dp[i]){
                    // counts if same are there
                    cnt[i]+=cnt[prev];
                }
            }maxi=max(maxi,dp[i]);
        }int nos=0;
        for(int i=0;i<n;i++){
            if(maxi==dp[i])
                nos+=cnt[i];
        }return nos;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        cout<<obj.NumberofLIS(n, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends