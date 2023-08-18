class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        vector<pair<int,int>>adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                    if(i!=j){
                    int dist=abs(points[i][0]-points[j][0])+abs(points[j][1]-points[i][1]);
                    adj[i].push_back({j,dist});
                    // adj[j].push_back({i,dist});
                    } 
                
            }
        }
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
        pq.push({0,0,});
        vector<int>vis(n,0);
        int sum=0;
        
        while(!pq.empty()){
            int wt=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            if(vis[node]==1) continue;
            vis[node]=1;
            sum+=wt;
            
            for(auto it:adj[node]){
                int n_wt=it.second;
                int n_node=it.first;
                if(!vis[n_node]){
                    pq.push({n_wt,n_node});
                }
            }
        }return sum;
    }
};
