//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>>adj[n];
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            int wt=roads[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        int destination=n-1;
        //{time,node}
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        vector<long long>dist(n,1e18);
        vector<long long>ways(n,0);
        ways[0]=1;
        q.push({0,0});
        dist[0]=0;
        int mod=(long)(1e9+7);
        while(!q.empty()){
            long long time=q.top().first;
            long long node=q.top().second;
            q.pop();
            
            for(auto it:adj[node]){
                long n_time=it.second;
                long adj_node=it.first;
                //this is the first time i am coming
                //with the shortest path
                if(time+n_time<dist[adj_node]){
                    dist[adj_node]=time+n_time;
                    ways[adj_node]=ways[node]%mod;
                    q.push({dist[adj_node],adj_node});
                }else if(time+n_time==dist[adj_node])
                    ways[adj_node]=(ways[adj_node]+ways[node])%mod;
            }
        }
        return ways[n-1]%mod;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends