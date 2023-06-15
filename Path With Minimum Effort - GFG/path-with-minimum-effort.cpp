//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        vector<vector<int>>dist(m,vector<int>(n,1e9));
        dist[0][0]=0;
        int drow[]={-1,0,1,0}; int dcol[]={0,1,0,-1};
       while(!pq.empty()){
           int diff=pq.top().first;
           int row=pq.top().second.first;
           int col=pq.top().second.second;
           pq.pop();
           if(row==m-1 && col==n-1) return diff;
           for(int i=0;i<4;i++){
               int n_row=row+drow[i];
               int n_col=col+dcol[i];
               if(n_row>=0 && n_col>=0 && n_row<m && n_col<n){
                   int new_effort=max(diff,abs(heights[n_row][n_col]-heights[row][col]));
                   if(new_effort<dist[n_row][n_col]){
                       dist[n_row][n_col]=new_effort;
                       pq.push({new_effort,{n_row,n_col}});
                   }
               }
           }
       }return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends