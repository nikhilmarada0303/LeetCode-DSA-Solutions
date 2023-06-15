//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
            // dijkstra's algorithm.....
       int m=grid.size();
       int n=grid[0].size();
       vector<vector<int>>dist(m,vector<int>(n,1e9));
       queue<pair<int,pair<int,int>>>q;
       q.push({0,{source.first,source.second}});
       dist[source.first][source.second]=0;
       while(!q.empty()){
           int steps=q.front().first;
           int row=q.front().second.first;
           int col=q.front().second.second;
           q.pop();
           if(row==destination.first && col==destination.second) return steps;
            int drow[]={-1,0,1,0};
            int dcol[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int n_row=row+drow[i];
                int n_col=col+dcol[i];
                if(n_row>=0 && n_row<m && n_col>=0 && n_col<n && grid[n_row][n_col]==1 && steps+1<dist[n_row][n_col]){
                    dist[n_row][n_col]=1+steps;
                    q.push({dist[n_row][n_col],{n_row,n_col}});
                }
            }
       }return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends