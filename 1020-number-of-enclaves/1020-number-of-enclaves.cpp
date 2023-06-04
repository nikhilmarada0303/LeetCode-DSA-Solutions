class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==(n-1) || j==0 || j==(m-1)){
                    if(grid[i][j]==1){
                    q.push({i,j});
                    vis[i][j]=1;}
                }
            }
        }
         int delRow[]={-1,0,1,0};
	    int delCol[]={0,1,0,-1};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
	            int newRow=row+delRow[i];
	            int newCol=col+delCol[i];
	            if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && vis[newRow][newCol]==0 && grid[newRow][newCol]==1){
	                vis[newRow][newCol]=1;
	                q.push({newRow,newCol});
	            }
	        }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1)
                    cnt++;
            }
        }
        return cnt;
    }
};