class Solution {
    int timer=0;
    private:
    void dfs(int node,int parent,vector<int>adj[],vector<int>&tin,vector<int>&low_t,vector<vector<int>>&bridges,vector<int>&vis){
        vis[node]=1;
        tin[node]=low_t[node]=timer;
        timer++;
        for(auto it:adj[node]){
            if(it==parent) continue;
            if(!vis[it]){
                dfs(it,node,adj,tin,low_t,bridges,vis);
                low_t[node]=min(low_t[node],low_t[it]);
                if(tin[node]<low_t[it])
                    bridges.push_back({it,node});
            }
            else{
                low_t[node]=min(low_t[node],low_t[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>tin(n);
        vector<int>low_t(n);
        vector<int>adj[n];
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<vector<int>>bridges;
        vector<int>vis(n,0);
        dfs(0,-1,adj,tin,low_t,bridges,vis);
        return bridges;
    }
};