class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int max_ans=INT_MIN;
            int len=0;
            int max_element=INT_MIN;
            for(int j=i;j<min(n,i+k);j++){
                len++;
                max_element=max(max_element,arr[j]);
                int sum=(len*max_element)+dp[j+1];
                max_ans=max(max_ans,sum);
            }dp[i]=max_ans;
        }return dp[0];
    }
};