class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
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
            if(stops>K && node==dst) break;
            for(auto it:adj[node]){
                int adj_node=it.first;
                int flight_cost=it.second;
                if(flight_cost+cost<dist[adj_node] && stops<=K){
                    dist[adj_node]=flight_cost+cost;
                    q.push({stops+1,{adj_node,dist[adj_node]}});
                }
            }
        }
        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }
};