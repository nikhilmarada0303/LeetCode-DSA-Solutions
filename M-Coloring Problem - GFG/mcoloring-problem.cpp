//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool func(int node,vector<int>&vis,vector<int>adj[],int n,int m){
        if(node==n){
            return true;
        }
        for(int i=1;i<=m;i++){
            int cnt1=0;int cnt2=0;    // to check adjacent nodes are coloured with same colr or not
            for(auto it:adj[node]){
                cnt1++;
                if(vis[it]!=i){
                   cnt2++;
                }
            }if (cnt1 == cnt2) {
                   vis[node] = i;
                   if (func(node + 1, vis, adj, n, m))
                     return true;
                   vis[node] = 0;
                }
        }return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int>adj[n];
    
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(graph[i][j]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
    vector<int>vis(n,0);
    return func(0,vis,adj,n,m);
    
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends