class Solution {
    private:
    bool isValid(int r,int c ,int n){
        return r>=0 && r<n && c>=0 && c<n;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>vis(n,vector<int>(n,0));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater
            <pair<int,pair<int,int>>>>pq;     //{depth,{row,col}};
        vis[0][0]=1;
        pq.push({grid[0][0],{0,0}});
        int drow[4]={-1,0,1,0};
        int dcol[4]={0,1,0,-1};
        int max_time=0;
        while(!pq.empty()){
            int depth=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            vis[row][col]=1;
            max_time=max(max_time,depth);
            if(row==n-1 && col==n-1) return max_time;
            for(int i=0;i<4;i++){
                int n_row=row+drow[i];
                int n_col=col+dcol[i];
                if(isValid(n_row,n_col,n) && vis[n_row][n_col]==0){
                    pq.push({grid[n_row][n_col],{n_row,n_col}});
                }
            }
        }return max_time;
    }
};