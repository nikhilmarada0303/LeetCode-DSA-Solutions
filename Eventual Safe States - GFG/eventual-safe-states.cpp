//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
   /* private:
      bool dfs(int node,vector<int> adj[],int vis[],int path_vis[],int check[]){
        vis[node]=1;
        path_vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                // if there is cycle ,it will return cycle and check will not be marked as 1 and it not a safe node 
                if(dfs(it,adj,vis,path_vis,check)==true) return true;
            }else if(path_vis[it])
                return true;
        }
        check[node]=1;       // safe node
        path_vis[node]=0;
        return false;
    }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        int check[V]={0};
         int vis[V]={0};
        int path_vis[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adj,vis,path_vis,check);
            }
        }vector<int>ans;
        for(int i=0;i<V;i++){
            if(check[i]==1)
                ans.push_back(i);
        }return ans;
    }*/ public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int>adjrev[V];
        vector<int>indegree(V,0);
        for(int i=0;i<V;i++){
            // i--->it     reverse  it---->i
            for(auto it:adj[i]){
                adjrev[it].push_back(i);
                indegree[i]++;
            }
        }//topo sort
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0)
                q.push(i);
        }
        vector<int>safe_nodes;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            safe_nodes.push_back(node);
            for(auto it:adjrev[node]){
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        sort(safe_nodes.begin(),safe_nodes.end());
        return safe_nodes;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends