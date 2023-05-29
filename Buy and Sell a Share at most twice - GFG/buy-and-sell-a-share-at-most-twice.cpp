//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


int maxProfit(vector<int>&price){
    int n=price.size();
   vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
    // base cases are already zeros
        //when cnt==0 ind and buy can be anything
        //when ind==n cnt and buy can be anything 
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
              for (int cnt = 1; cnt <= 2; cnt++) {
                if (buy)
                  dp[ind][buy][cnt] = max(-price[ind] + dp[ind + 1][0][cnt],
                                          dp[ind + 1][1][cnt]);
                else
                  dp[ind][buy][cnt] = max(price[ind] + dp[ind + 1][1][cnt - 1],
                                          dp[ind + 1][0][cnt]);
              }
            }
        }return dp[0][1][2];
    
    
}

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends