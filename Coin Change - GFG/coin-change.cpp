//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    long long int count(int coins[], int n, int sum) {
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