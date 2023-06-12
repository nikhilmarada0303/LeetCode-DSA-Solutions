//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
        void dfs(int node,vector<vector<int>>& adj,vector<int>& vis,stack<int>&st){
            vis[node]=1;
            for(auto it:adj[node]){
                if(!vis[it])
                dfs(it,adj,vis,st);
            }
            st.push(node);
        }
        void dfs2(int node,vector<int>adjT[],vector<int>&vis){
            vis[node]=1;
            for(auto it:adjT[node]){
                if(!vis[it])
                    dfs2(it,adjT,vis);
            }
        }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        stack<int>st;
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){                    // step 1 (store according to finishing time in stack)
            if(!vis[i]){
                dfs(i,adj,vis,st);
            }
        }
        vector<int>adjT[V];
        for(int i=0;i<V;i++){                    // step2 reverse the graph
           vis[i]=0;
            for(auto it:adj[i])
                adjT[it].push_back(i);
        }
        int scc=0;

        while(!st.empty()){
            int node=st.top();                   //step 3 cnt scc
            st.pop();
            if(!vis[node]){
                scc++;
                dfs2(node,adjT,vis);
            }
        }
        return scc;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends