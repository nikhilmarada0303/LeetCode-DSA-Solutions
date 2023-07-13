class Solution {
public:
    int change(int sum, vector<int>& coins) {
        int n=coins.size();
         vector<long>prev(sum+1,0),curr(sum+1,0);
       for(int t=0;t<=sum;t++){
           prev[t]=(t%coins[0]==0);
       }
        for(int ind=1;ind<n;ind++){
            for(int target=0;target<=sum;target++){
                long long notTake=prev[target];
                long long take=0;
                if(coins[ind]<=target)
                take=curr[target-coins[ind]];
                curr[target]=take+notTake;
        
            }prev=curr;
        }
        return prev[sum];
    }
};