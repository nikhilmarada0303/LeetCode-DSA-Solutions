class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int n=arr.size();
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