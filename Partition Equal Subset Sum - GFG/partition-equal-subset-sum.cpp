//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isSubsetSum(int arr[], int sum,int N){
        int n=N;
        vector<bool>prev(sum+1,0),curr(sum+1,0);
        
       prev[0]=curr[0]=true;
        if(arr[0]<=sum)
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
    int equalPartition(int N, int arr[])
    {
        int total_sum=0;
        for(int i=0;i<N;i++)
            total_sum+=arr[i];
        if(total_sum%2==1) return false;
        int sum=total_sum/2;
        return isSubsetSum(arr,sum,N);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends