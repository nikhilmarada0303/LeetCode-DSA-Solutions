// class Solution {
// public:
//     int minCostConnectPoints(vector<vector<int>>& edges) {
//         int n=edges.size();
        
//         vector<pair<int,int>>adj[n];
//         for(auto it:edges){
//             int node=it[0];
            
//             for(auto i:edges){
//                 if(i[0]!=node){
//                     int dist=abs(i[0]-it[0])+abs(it[1]-i[1]);
//                     adj[it[0]].push_back({i[0],dist});
//                      adj[i[0]].push_back({it[0],dist});
                    
//                 }
//             }
//         }
//         vector<int>vis(n,0);
// priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
//         pq.push({0,{0,-1}});
        
//         int sum=0;
//         while(!pq.empty()){
//             int wt=pq.top().first;
//             int node=pq.top().second.first;
//             int parent=pq.top().second.second;
//             pq.pop();
            
//             if(vis[node]==1) continue;
//             vis[node]=1;
//             sum+=wt;
            
//             for(auto it:adj[node]){
//                 int n_wt=it.second;
//                 int n_node=it.first;
//                 int n_parent=node;
//                 if(!vis[n_node])
//                     pq.push({n_wt,{n_node,n_parent}});
//             }
            
//             }return sum;
//     }
// };
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        vector<vector<int>> adj(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i][j] = dist;
                adj[j][i] = dist;
            }
        }
        
        vector<int> vis(n, 0);
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, -1}});
        
        int sum = 0;
        while (!pq.empty()) {
            int wt = pq.top().first;
            int node = pq.top().second.first;
            int parent = pq.top().second.second;
            pq.pop();
            
            if (vis[node] == 1) continue;
            vis[node] = 1;
            sum += wt;
            
            for (int i = 0; i < n; ++i) {
                if (i != node && !vis[i]) {
                    int n_wt = adj[node][i];
                    int n_node = i;
                    int n_parent = node;
                    pq.push({n_wt, {n_node, n_parent}});
                }
            }
        }
        
        return sum;
    }
};
