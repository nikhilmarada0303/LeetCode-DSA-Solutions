//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,
                 int distanceThreshold) {
       /* vector<pair<int,int>>adj[n];
        // cost,node
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int cnt_city=n;
        int city_no=-1;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        for(int i=0;i<n;i++){
            int cnt=0;
             vector<int>dist(n,1e9);
             pq.push({0,i});
             dist[i]=0;
             while(!pq.empty()){
                 int cost=pq.top().first;
                 int node=pq.top().second;
                 pq.pop();
                 for(auto it:adj[node]){
                     int wt=it.second;
                     int adj_node=it.first;
                     if(cost+wt<dist[adj_node]){
                         dist[adj_node]=cost+wt;
                         pq.push({dist[adj_node],adj_node});
                     }
                 }
             }
             for(int j=0;j<n;j++){
                 if(dist[j]<=distanceThreshold) cnt++;
             }
             if(cnt_city>=cnt){
                 cnt_city=cnt;
                 city_no=i;
             }
        }
    return city_no;*/
    // floyd warshall 
    vector<vector<int>>dist(n,vector<int>(n,1e9));
     for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            dist[u][v]=wt;
            dist[v][u]=wt;
        }
        for(int i=0;i<n;i++) dist[i][i]=0;
        
         for(int k=0;k<n;k++){
	        for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
	                
	                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
	            }
	        }
	    }
	     int cnt_city=n;
        int city_no=-1;
        for(int i=0;i<n;i++){
            int cnt=0;
	        for(int j=0;j<n;j++){
                 if(dist[i][j]<=distanceThreshold) cnt++;
             }
             if(cnt_city>=cnt){
                 cnt_city=cnt;
                 city_no=i;
             }
        }return city_no;
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
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends