//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<pair<int,int>>q;
        vector<int>dist(1e5,1e9);
        dist[start]=0;
        //{steps,number}
        q.push({0,start});
        int mod=1e5;
        while(!q.empty()){
            auto it=q.front();
            int steps=it.first;
            int number=it.second;
            q.pop();
            if(end==number) return steps;
            for(auto it:arr){
                int number_new=(it*number)%mod;
                if(steps+1<dist[number_new]){
                    dist[number_new]=steps+1;
                    q.push({steps+1,number_new});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends