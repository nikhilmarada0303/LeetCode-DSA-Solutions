//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool func(vector<int>&arr,int target,int ind, vector<vector<int>>&dp){
        if(target==0) return true;
        if(ind==0) return arr[0]==target;
        if(dp[ind][target]!=-1) return dp[ind][target];
        bool take=false;
        if(arr[ind]<=target)
        take=func(arr,target-arr[ind],ind-1,dp);
         bool nottake=func(arr,target,ind-1,dp);
        return dp[ind][target]=take | nottake;
    }
   
bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        vector<bool>prev(sum+1,0),curr(sum+1,0);
        
       prev[0]=curr[0]=true;
        prev[arr[0]]=true;
        
         for(int ind=1;ind<n;ind++){
             for(int target=1;target<=sum;target++){
                   bool take=false;
                    if(arr[ind]<=target)
                  take=prev[target-arr[ind]];
            bool nottake=prev[target];
            curr[target]=take | nottake;
             }prev=curr;
         }return prev[sum];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends