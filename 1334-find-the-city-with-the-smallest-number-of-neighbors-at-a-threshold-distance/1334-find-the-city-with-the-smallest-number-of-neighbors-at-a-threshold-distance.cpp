class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
         vector<pair<int,int>>adj[n];
        // cost,node
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int cnt_city=n;
        int city_no=-1;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        for(int i=0;i<n;i++){
            int cnt=0;
             vector<int>dist(n,1e9);
             pq.push({0,i});
             dist[i]=0;
             while(!pq.empty()){
                 int cost=pq.top().first;
                 int node=pq.top().second;
                 pq.pop();
                 for(auto it:adj[node]){
                     int wt=it.second;
                     int adj_node=it.first;
                     if(cost+wt<dist[adj_node]){
                         dist[adj_node]=cost+wt;
                         pq.push({dist[adj_node],adj_node});
                     }
                 }
             }
             for(int j=0;j<n;j++){
                 if(dist[j]<=distanceThreshold) cnt++;
             }
             if(cnt_city>=cnt){
                 cnt_city=cnt;
                 city_no=i;
             }
        }
    return city_no;
    }
};