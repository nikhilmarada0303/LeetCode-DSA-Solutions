class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int vis[n][m];
        int cntFresh=0;
        // {{r,c},time}
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }else
                    vis[i][j]=0;
                if(grid[i][j]==1)
                    cntFresh++;
            }
        }int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};
        int tp=0;
        int cnt=0;
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int time=q.front().second;
            tp=max(tp,time);
            q.pop();
            for(int i=0;i<4;i++){
                int newRow=row+delRow[i];
                int newCol=col+delCol[i];
                if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && grid[newRow][newCol]==1 && vis[newRow][newCol]==0){
                    vis[newRow][newCol]=2;
                    q.push({{newRow,newCol},time+1});
                    cnt++;
                }
            }
        }
        if(cnt!=cntFresh) return -1;
        return tp;
        
    }
};