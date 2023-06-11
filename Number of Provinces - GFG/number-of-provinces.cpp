//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

/*class Solution {
    private:
    void dfs(int node,vector<int>adjls[],int vis[]){
        vis[node]=1;
        for(auto it:adjls[node]){
            if(!vis[it])
                dfs(it,adjls,vis);
        }
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int>adjls[V];
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]==1 && i!=j){
                    adjls[j].push_back(i);
                    adjls[i].push_back(j);
                }
            }
        }
        int vis[V]={0};
        int cnt=0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adjls,vis);
                cnt++;
            }
        }return cnt;
    }
};*/

class disjointSet{
    public:
   vector<int>size,parent;  
    disjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
    }
    int findParent(int node){
        if(node==parent[node]) return node;
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

class Solution{
    public:
     int numProvinces(vector<vector<int>> adj, int V) {
         disjointSet ds(V);
      for(int i=0;i<V;i++){
          for(int j=0;j<V;j++){
              if(adj[i][j]==1)
                ds.unionBySize(i,j);
          }
      }
      int cnt=0;
      // check for number of diff parent nodes
      for(int i=0;i<V;i++){
          if(ds.parent[i]==i)
            cnt++;
      }
      return cnt;  
     }
};




















//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends