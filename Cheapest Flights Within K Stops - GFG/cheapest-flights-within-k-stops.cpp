//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        vector<pair<int,int>>adj[n];
        for(int i=0;i<flights.size();i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int wt=flights[i][2];
            adj[u].push_back({v,wt});
        }
        vector<int>dist(n,1e9);
        //{stops,{node,distance}}
        queue<pair<int,pair<int,int>>>q;
        dist[src]=0;
        q.push({0,{src,0}});
        while(!q.empty()){
            auto it=q.front();
            int node=it.second.first;
            int cost=it.second.second;
            int stops=it.first;
            q.pop();
            if(stops>K) continue;
            for(auto it:adj[node]){
                int adj_node=it.first;
                int flight_cost=it.second;
                if(flight_cost+cost<dist[adj_node]){
                    dist[adj_node]=flight_cost+cost;
                    q.push({stops+1,{adj_node,dist[adj_node]}});
                }
            }
        }
        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends