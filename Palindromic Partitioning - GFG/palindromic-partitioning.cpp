//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    bool ispalindrome(int i,int j,string &s){
        if(i>=j) return true;
        if(s[i]!=s[j]) return false;
        return ispalindrome(i+1,j-1,s);
    } 
    
   
public:
    int palindromicPartition(string &s)
    {
      int n=s.size();
        vector<int>dp(n+1,0);
        vector<vector<int>>palindrome_dp(n+1,vector<int>(n+1,-1));
        
        for(int ind=n-1;ind>=0;ind--){
            
            int mincost=INT_MAX;
    
            for(int i=ind;i<s.size();i++){
                if(ispalindrome(ind,i,s)){
                    int cost=1+dp[i+1];
                    mincost=min(mincost,cost);
                }
            }
            dp[ind]=mincost;
        }
        return (dp[0]-1);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends