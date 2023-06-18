//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#define ll long long int 
int mod=1003;
class Solution{
public:
    int countWays(int n, string exp){
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+1,vector<int>(2,0)));
        for(int i=0; i<n; i++){
        dp[i][i][1] = exp[i] == 'T';
        dp[i][i][0] = exp[i] == 'F';
    }
    for(int i=n-1;i>=0;i--){
        for(int j=i+1;j<n;j++){
            for(int isTrue=0;isTrue<2;isTrue++){
                if(i>j) continue;
                
            ll ways=0;
            for(int ind=i+1;ind<=j-1;ind=ind+2){
                ll lT=dp[i][ind-1][1];                  //left true
                ll lF=dp[i][ind-1][0];                  //left false
                ll rT=dp[ind+1][j][1];                  //right true
                ll rF=dp[ind+1][j][0];                  //right false

                if(exp[ind]=='&'){
                if(isTrue){
                ways=(ways+(lT*rT)%mod)%mod;
                }else
                ways=(ways+(lT*rF)%mod+(lF*rT)%mod+(lF*rF)%mod)%mod;
                }
                else if(exp[ind]=='|'){
                if(isTrue){
                ways=(ways+(lT*rF)%mod+(lF*rT)%mod+(lT*rT)%mod)%mod;
                }
                else   
                ways=(ways+(lF*rF)%mod)%mod;
                }
                else if(exp[ind]=='^'){
                  if (isTrue) {
                    ways = (ways + (lT * rF) % mod + (lF * rT) % mod) % mod;
                  } else
                    ways = (ways + (lT * rT) % mod + (lF * rF) % mod) % mod;
                }
            }
            dp[i][j][isTrue] = ways%mod;
            }
        }
    }return dp[0][n-1][1];
    
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends