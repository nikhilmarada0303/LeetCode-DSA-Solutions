class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
       vector<vector<int>>vis(n,vector<int>(m,0));
         vector<vector<int>>dist(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0)
                    vis[i][j]=1;
            }
        }
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j])
                    q.push({0,{i,j}});
            }
        }
        while(!q.empty()){
            int row=q.front().second.first;
            int col=q.front().second.second;
            int dis=q.front().first;
            q.pop();
            dist[row][col]=dis;
            
            int drow[4]={-1,0,1,0};
            int dcol[4]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int n_row=row+drow[i];
                int n_col=col+dcol[i];
                if(n_row>=0 && n_row<n && n_col>=0 && n_col<m && vis[n_row][n_col]==0 ){
                    vis[n_row][n_col]=1;
                    q.push({dis+1,{n_row,n_col}});
                }
            }
        }return dist;
    }
};