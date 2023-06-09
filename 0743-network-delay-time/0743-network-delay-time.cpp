class Solution {
public:
    int networkDelayTime(vector<vector<int>>& flights, int n, int k) {
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
                maxi=max(maxi,dist[i]);
        }if(maxi==1e9 ) return -1;
        return maxi;
    }
};