//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int k, int n, int price[]) {
         vector<vector<int>>after(2,vector<int>(k+1,0));
     vector<vector<int>>curr(2,vector<int>(k+1,0));
     
    // base cases are already zeros
        //when cnt==0 ind and buy can be anything
        //when ind==n cnt and buy can be anything 
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
              for (int cnt = 1; cnt <= k; cnt++) {
                if (buy)
                  curr[buy][cnt] = max(-price[ind] + after[0][cnt],after[1][cnt]);
                else
                 curr[buy][cnt] = max(price[ind] + after[1][cnt - 1],after[0][cnt]);
              }after=curr;
            }
        }return after[1][k];
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