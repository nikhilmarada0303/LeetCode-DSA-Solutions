class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
         int m=heights.size();
        int n=heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        vector<vector<int>>dist(m,vector<int>(n,1e9));
        dist[0][0]=0;
        int drow[]={-1,0,1,0}; int dcol[]={0,1,0,-1};
        while(!pq.empty()){
            auto it=pq.top();
            int diff=it.first;
            int row=it.second.first;
            int col=it.second.second;
            pq.pop();
            if(row==m-1 && col==n-1) return diff;

            for(int i=0;i<4;i++){
                int n_row=row+drow[i];
                int n_col=col+dcol[i];
                if(n_row>=0 && n_row<m && n_col>=0 && n_col<n){
                    int new_effort=max(diff,abs(heights[row][col]-heights[n_row][n_col]));
                    if(new_effort<dist[n_row][n_col]){
                        dist[n_row][n_col]=new_effort;
                        pq.push({dist[n_row][n_col],{n_row,n_col}});
                    }
                }
            }
        }return 0;
    }
};