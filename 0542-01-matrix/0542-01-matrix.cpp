class Solution {
    
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        	    int n=grid.size();
	    int m=grid[0].size();
	    queue<pair<pair<int,int>,int>>q;
	    vector<vector<int>>vis(n,vector<int>(m,0));
	    vector<vector<int>>dis(n,vector<int>(m,0));
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==0){
	                vis[i][j]=1;
	                q.push({{i,j},0});
	            }else
	                vis[i][j]=0;
	        }
	    }
	    int delRow[]={-1,0,1,0};
	    int delCol[]={0,1,0,-1};
	    while(!q.empty()){
	        int row=q.front().first.first;
	        int col=q.front().first.second;
	        int dist=q.front().second;
	        dis[row][col]=dist;
	        q.pop();
	        for(int i=0;i<4;i++){
	            int newRow=row+delRow[i];
	            int newCol=col+delCol[i];
	            if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && vis[newRow][newCol]==0 ){
	                vis[newRow][newCol]=1;
	                q.push({{newRow,newCol},dist+1});
	            }
	        }
	        
	    }return dis;
	    
    }
};