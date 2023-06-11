//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class disjointSet{
    public:
        vector<int>size,parent;
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


class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        disjointSet ds(n);
        int cntExtraEdges=0;
        for(auto it:edge){
            int u=it[0];
            int v=it[1];
            if(ds.findParent(u)==ds.findParent(v)) cntExtraEdges++;
            else{
                ds.unionBySize(u,v);
            }
        }
        int num_of_comp=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i)
                num_of_comp++;
        }
        int required_edges=num_of_comp-1;
        if(cntExtraEdges>=required_edges)
            return required_edges;
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends