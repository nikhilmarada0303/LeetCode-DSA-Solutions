//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    long long maximumProfit(vector<long long>&prices, int n) {
        long long curr_buy,curr_notbuy,ahead_buy,ahead_notbuy;
         ahead_notbuy=ahead_buy=0;
        
        for(int ind=n-1;ind>=0;ind--){
            
            curr_buy=max(-prices[ind]+ahead_notbuy,0+ahead_buy);
                
            curr_notbuy=max(prices[ind]+ahead_buy,0+ahead_notbuy);
                    
            ahead_buy=curr_buy;
            ahead_notbuy=curr_notbuy;
            
        }return ahead_buy;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends