class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
         int n=arr.size();
         vector<int>dp(n,1),hash(n);
         sort(arr.begin(),arr.end());
        int maxi=INT_MIN;
        int lastindex=1;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int prev=0;prev<i;prev++){
                if(((arr[i]%arr[prev]==0) || (arr[prev]%arr[i]==0)) && 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
            }if(dp[i]>maxi){
                maxi=dp[i];
                lastindex=i;
            }
        }vector<int>temp;
        temp.push_back(arr[lastindex]);
        while(hash[lastindex]!=lastindex){
            lastindex=hash[lastindex];
            temp.push_back(arr[lastindex]);
        }
        return temp;
    }
};