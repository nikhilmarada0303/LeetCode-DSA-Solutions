//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class disjointSet{
    vector<int>size,parent;
    public:
        disjointSet(int n){
            size.resize(n+1,1);
            parent.resize(n+1);
            for(int i=0;i<=n;i++)
                parent[i]=i;
        }
        int findParent(int node){
            if(node==parent[node])
                return node;
            return parent[node]=findParent(parent[node]);
        }
        void unionBySize(int u,int v){
            int ult_u=findParent(u);
            int ult_v=findParent(v);
            if(size[ult_u]<size[ult_v]){
                parent[ult_u]=ult_v;
                size[ult_v]+=size[ult_u];
            }
            else{
                parent[ult_v]=ult_u;
                size[ult_u]+=size[ult_v];
            }
        }
};


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // prim's algo
       /* int sum=0;
        vector<pair<int,int>>mst;              //To store MST
        vector<int>vis(V,0);
        // {weight,{node,parent}}
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,-1}});
        //ElogE+ElogE
        //ElogE
        while(!pq.empty()){             //E
            auto it=pq.top();
            int node=it.second.first;
            int parent=it.second.second;         
            int wt=it.first;
            pq.pop();                       //logE
            
            if(vis[node]) continue;
            
            vis[node]=1;
            sum+=wt;
            mst.push_back({node,parent});
            //ElogE
            for(auto it:adj[node]){                  //E
                int n_wt=it[1];
                int n_node=it[0];
                if(!vis[n_node]){
                    pq.push({n_wt,{n_node,node}});       //logE
                }
            }
        }return sum;*/
        // krushkal's algo  
        vector<pair<int,pair<int,int>>> edges;          //{wt,{u,v}}
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                int wt=it[1];
                int adj_node=it[0];
                int node=i;
                edges.push_back({wt,{node,adj_node}});
            }
        }
        sort(edges.begin(),edges.end());
         disjointSet ds(V);
        int mstWt=0;
        for(auto it:edges){
            int wt=it.first;
            int u=it.second.first;
            int v=it.second.second;
            if(ds.findParent(u)!=ds.findParent(v)){
                mstWt+=wt;
                ds.unionBySize(u,v);
            }
        }
        return mstWt;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends