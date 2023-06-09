//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int minimumCost(vector<vector<int>>& flights, int n, int k) {
        //dijkstra's algo
         vector<pair<int,int>>adj[n+1];
        for(int i=0;i<flights.size();i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int wt=flights[i][2];
            adj[u].push_back({v,wt});
        }
        vector<int>dist(n+1,1e9);
        dist[k]=0;
        //cost,node
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> q; 
        q.push({0,k});
        while(!q.empty()){
            int cost=q.top().first;
            int node=q.top().second;
            q.pop();
            for(auto it:adj[node]){
                int adj_node=it.first;
                int weight=it.second;
                if(weight+cost<dist[adj_node]){
                    dist[adj_node]=weight+cost;
                    q.push({dist[adj_node],adj_node});
                }
            }
        }int maxi=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==1e9) return -1;
            else{
                maxi=max(maxi,dist[i]);
            }
        }return maxi;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size,vector<int>(3));
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i]=temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}

// } Driver Code Ends