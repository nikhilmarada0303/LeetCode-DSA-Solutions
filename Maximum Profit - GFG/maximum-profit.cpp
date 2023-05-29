//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:

    int maxProfit(int k, int n, int price[]) {
        vector<int>curr(2*k+1,0);
        vector<int>ahead(2*k+1,0);
        // base cases are inititated to zero
        for(int ind=n-1;ind>=0;ind--){
            for(int transaction=(2*k)-1;transaction>=0;transaction--){
                int profit=0;
                if(transaction%2==0)
                profit=max(-price[ind]+ahead[transaction+1],ahead[transaction]);
                else
                  profit=max(price[ind]+ahead[transaction+1],ahead[transaction]);
                  curr[transaction]=profit;
            }ahead=curr;
        }return ahead[0];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends