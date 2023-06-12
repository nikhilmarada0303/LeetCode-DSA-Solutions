//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
        private:
        bool isValid(int r,int c ,int n){
            return r>=0 && r<n && c>=0 && c<n;
    }
  public:
    int Solve(int n, vector<vector<int>>& grid) {
                vector<vector<int>>vis(n,vector<int>(n,0));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater
            <pair<int,pair<int,int>>>>pq;     //{depth,{row,col}};
        vis[0][0]=1;
        pq.push({grid[0][0],{0,0}});
        int drow[4]={-1,0,1,0};
        int dcol[4]={0,1,0,-1};
        int min_time=0;
        while(!pq.empty()){
            int depth=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            vis[row][col]=1;
            min_time=max(min_time,depth);
            if(row==n-1 && col==n-1) return min_time;
            for(int i=0;i<4;i++){
                int n_row=row+drow[i];
                int n_col=col+dcol[i];
                if(isValid(n_row,n_col,n) && vis[n_row][n_col]==0){
                    pq.push({grid[n_row][n_col],{n_row,n_col}});
                }
            }
        }return min_time;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < n; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution ob;
        cout << ob.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends