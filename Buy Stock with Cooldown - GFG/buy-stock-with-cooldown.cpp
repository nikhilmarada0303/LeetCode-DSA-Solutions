//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long maximumProfit(vector<long long>&prices, int n) {
         vector<long long>front1(2,0);
         vector<long long>front2(2,0);
         vector<long long>curr(2,0);
        for(int ind=n-1;ind>=0;ind--){
            
                 curr[1]=max(-prices[ind]+front1[0],0+front1[1]);
                
                    curr[0]=max(prices[ind]+front2[1],0+front1[0]);
                front2=front1;
                front1=curr;
        
        }return curr[1];
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