//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
   /* private:
    bool dfs(int node,vector<int> adj[],int vis[],int path_vis[]){
        vis[node]=1;
        path_vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,adj,vis,path_vis)==true) return true;
            }else if(path_vis[it])
                return true;
        }path_vis[node]=0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V]={0};
        int path_vis[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,path_vis)==true) return true;
            }
        }return false;
    }*/
    public:
     bool isCyclic(int V, vector<int> adj[]) {
          vector<int>in_degree(V,0);
	    for(int i=0;i<V;i++){
	        for(auto it:adj[i])
	            in_degree[it]++;
	    }
	    queue<int>q;
	    for(int i=0;i<V;i++){
	        if(in_degree[i]==0)
	            q.push(i);
	    }int cnt=0;
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        cnt++;
	        for(auto it:adj[node]){
	            in_degree[it]--;
	            if(in_degree[it]==0)
	                q.push(it);
	        }
	    }if(cnt==V) return false;
	    return true;
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
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends