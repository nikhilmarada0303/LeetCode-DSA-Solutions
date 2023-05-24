//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int mod=(int)(1e9+7);
	int perfectSum(int arr[], int n, int sum)
	{
         vector<int>prev(sum+1,0),curr(sum+1,0);
          if(arr[0]==0)
          prev[0]=2;
          else
          prev[0]=1;
          if(arr[0]!=0){
              if(arr[0]<=sum)
              prev[arr[0]]=1;
          }
          for(int ind=1;ind<n;ind++){
              for(int target=0;target<=sum;target++){
                   int take=0;
	                if(arr[ind]<=target)
	                take=prev[target-arr[ind]];
	                int notTake=prev[target];
	                curr[target]=(take + notTake)%mod;
              }
              prev=curr;
          }return prev[sum];
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends