//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    
    int minimumEnergy(vector<int>& h, int n) {
	  int prev2=0;
	  int prev=0;
        for(int i=1;i<n;i++){
            int left=prev+abs(h[i]-h[i-1]);
            int right=INT_MAX;
            if(i>1)
            right=prev2+abs(h[i]-h[i-2]);
            int curr=((left>right)?right:left);
            
            prev2=prev;
            prev=curr;
        }return prev;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends