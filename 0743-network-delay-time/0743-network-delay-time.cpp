class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        for(auto it:times){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(n+1,1e9);
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            int node=pq.top().second;
            int dis=pq.top().first;
            pq.pop();
            
            for(auto it:adj[node]){
                int adjacentnode=it.first;
                int weight=it.second;
                if(weight+dis<dist[adjacentnode]){
                    dist[adjacentnode]=weight+dis;
                    pq.push({dist[adjacentnode],adjacentnode});
                }
            }
        }int m=0;
        for(int i=1;i<=n;i++){
            m=max(m,dist[i]);
            if(dist[i]==1e9) return -1;
        }return m;
    }
};