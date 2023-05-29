//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    //Function to find the days of buying and selling stock for max profit.
    vector<vector<int> > stockBuySell(vector<int> prices, int n){
    
    vector<vector<int>> result;
    int buy = 0, sell = 0;

    // Traverse the prices array
    for (int i = 1; i < n; i++) {
        // If the current price is greater than the previous price,
        // update the sell index
        if (prices[i] > prices[i - 1]) {
            sell = i;
        }
        // If the current price is less than or equal to the previous price
        // and there was a profit opportunity, add it to the result
        else if (prices[i] <= prices[i - 1] && buy < sell) {
            result.push_back({buy, sell});
            buy = sell = i;
        }
        // If the current price is less than or equal to the previous price
        // and there was no profit opportunity, update the buy and sell indices
        else {
            buy = sell = i;
        }
    }

    // Check if there is a pending profit opportunity
    if (buy < sell) {
        result.push_back({buy, sell});
    }

    return result;
    }
};

//{ Driver Code Starts.

int check(vector<vector<int>> ans, vector<int> A, int p)
{
    int c = 0;
    for(int i=0; i<ans.size(); i++)
        c += A[ans[i][1]]-A[ans[i][0]];
    return (c==p) ? 1 : 0;
}

int main()
{   
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A(n);
        for (int i=0; i<n; ++i){
            cin>>A[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.stockBuySell(A, n);
        int p = 0;
        for(int i=0; i<n-1; i++)
        {
            int x = A[i+1]-A[i];
            if(x>0)
                p += x;
        }
        if(ans.size()==0)
            cout<<"No Profit";
        else{
            cout<<check(ans,A,p);
        }cout<<endl;
    }
    return 0;
}


// } Driver Code Ends