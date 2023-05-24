//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
  
	int minDifference(int arr[], int n)  { 
	    int t_sum=0;
	    for(int i=0;i<n;i++)
	    t_sum+=arr[i];
	    int sum=t_sum;
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
         }
         int mini=1e9;
         for(int i=0;i<=t_sum/2;i++){
             if(prev[i]==true){
                 int s1=i;
                 int s2=t_sum-s1;
                 mini=min(mini,abs(s1-s2));
             }
         }return mini;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends