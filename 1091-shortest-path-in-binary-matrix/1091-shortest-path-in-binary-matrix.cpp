class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        dist[0][0]=1;
        q.push({1,{0,0}});
        while(!q.empty()){
            int distance=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            if(row==n-1 && col==n-1) return distance;
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int n_row=row+i;
                    int n_col=col+j;
                    if(n_row>=0 && n_row<n && n_col>=0 && n_col<n && grid[n_row][n_col]==0 && dist[n_row][n_col]==1e9){
                        dist[n_row][n_col]=1+distance;
                        q.push({dist[n_row][n_col],{n_row,n_col}});
                    }
                }
            }
        }return -1;
    }
};