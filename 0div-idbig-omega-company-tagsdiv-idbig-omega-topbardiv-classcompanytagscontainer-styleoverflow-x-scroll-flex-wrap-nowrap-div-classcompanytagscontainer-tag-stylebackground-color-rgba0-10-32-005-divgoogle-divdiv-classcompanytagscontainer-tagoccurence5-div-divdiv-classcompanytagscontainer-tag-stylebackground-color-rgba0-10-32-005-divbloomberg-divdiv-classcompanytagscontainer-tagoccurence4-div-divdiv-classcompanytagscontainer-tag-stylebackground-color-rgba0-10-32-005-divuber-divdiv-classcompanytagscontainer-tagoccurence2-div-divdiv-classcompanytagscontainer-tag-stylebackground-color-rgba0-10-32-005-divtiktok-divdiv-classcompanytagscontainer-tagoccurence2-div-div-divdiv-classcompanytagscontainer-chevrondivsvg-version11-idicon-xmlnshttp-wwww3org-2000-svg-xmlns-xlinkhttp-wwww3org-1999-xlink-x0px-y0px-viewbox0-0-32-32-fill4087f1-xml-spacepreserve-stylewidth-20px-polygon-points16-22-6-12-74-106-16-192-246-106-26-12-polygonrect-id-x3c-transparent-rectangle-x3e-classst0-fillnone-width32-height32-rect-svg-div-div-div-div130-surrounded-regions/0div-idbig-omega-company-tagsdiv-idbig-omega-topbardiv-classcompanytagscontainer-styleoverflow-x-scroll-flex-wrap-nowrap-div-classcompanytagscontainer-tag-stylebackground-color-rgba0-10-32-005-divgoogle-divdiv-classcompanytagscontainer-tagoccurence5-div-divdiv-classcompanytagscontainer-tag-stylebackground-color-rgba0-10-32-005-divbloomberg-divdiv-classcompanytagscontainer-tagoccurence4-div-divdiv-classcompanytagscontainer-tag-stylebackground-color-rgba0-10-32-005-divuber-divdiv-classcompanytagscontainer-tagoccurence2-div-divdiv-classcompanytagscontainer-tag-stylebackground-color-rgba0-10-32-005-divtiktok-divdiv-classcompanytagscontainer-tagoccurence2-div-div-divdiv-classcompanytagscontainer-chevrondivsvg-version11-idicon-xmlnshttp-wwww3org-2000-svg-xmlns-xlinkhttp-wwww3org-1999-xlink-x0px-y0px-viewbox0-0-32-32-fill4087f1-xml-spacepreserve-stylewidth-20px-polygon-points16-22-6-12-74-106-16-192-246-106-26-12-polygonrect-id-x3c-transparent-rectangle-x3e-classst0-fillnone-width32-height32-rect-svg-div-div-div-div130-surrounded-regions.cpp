class Solution {
private:
     void dfs(int row,int col,vector<vector<char>>& board,vector<vector<int>>&vis){
         int n=board.size();
        int m=board[0].size();
        vis[row][col]=1;
        int drow[4]={-1,0,1,0};
        int dcol[4]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int newRow=row+drow[i];
            int newCol=col+dcol[i];
            if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && !vis[newRow][newCol] && board[newRow][newCol]=='O')
                dfs(newRow,newCol,board,vis);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        // traverse first row and last row
        for(int j=0;j<m;j++){
            //first row
            if(!vis[0][j] && board[0][j]=='O')
               dfs(0,j,board,vis);
            //last row
            if(!vis[n-1][j] && board[n-1][j]=='O')
                dfs(n-1,j,board,vis);
        }//traverse first col and last col
        for(int i=0;i<n;i++){
            //first col
            if(!vis[i][0] && board[i][0]=='O')
                dfs(i,0,board,vis);
            //last col
            if(!vis[i][m-1] && board[i][m-1]=='O')
                dfs(i,m-1,board,vis);
                
        }for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(!vis[i][j] && board[i][j]=='O')
                    board[i][j]='X';
            }
        }
    } 

};