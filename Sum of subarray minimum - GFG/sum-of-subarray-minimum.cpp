//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int sumSubarrayMins(int n, vector<int> &arr) {
         vector<int>nxtSmaller(n);
        vector<int>prevSmaller(n);
        stack<int>st;
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()) nxtSmaller[i]=n-1;
            else  nxtSmaller[i]=st.top()-1;
            st.push(i);
        }
        while(!st.empty()) st.pop();
        
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }if(st.empty()) prevSmaller[i]=0;
            else  prevSmaller[i]=st.top()+1;
            st.push(i);
        }
        long sum=0;
        int mod=(int)(1e9+7);
       
        for(int i=0;i<n;i++){
            long t=arr[i];
            long h=t*((nxtSmaller[i]-i+1)*(i-prevSmaller[i]+1));
            sum=(sum+h)%mod;
        }return sum%mod;
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
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        cout << obj.sumSubarrayMins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends