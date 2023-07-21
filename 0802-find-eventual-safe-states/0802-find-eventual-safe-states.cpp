class Solution {
     private:
      bool dfs(int node,vector<vector<int>>&adj, vector<int>&vis,vector<int>&path_vis,vector<int>&check){
        vis[node]=1;
        path_vis[node]=1;
        for(auto it=adj[node].begin();it<adj[node].end();it++){
            if(!vis[*it]){
                // if there is cycle ,it will return cycle and check will not be marked as 1 and it not a safe node 
                if(dfs(*it,adj,vis,path_vis,check)==true) return true;
            }else if(path_vis[*it])
                return true;
        }
        check[node]=1;       // safe node
        path_vis[node]=0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int V=adj.size();
        vector<int>check(V,0);
        vector<int>vis(V,0);
        vector<int>path_vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adj,vis,path_vis,check);
            }
        }vector<int>ans;
        for(int i=0;i<V;i++){
            if(check[i]==1)
                ans.push_back(i);
        }return ans;
    }
};