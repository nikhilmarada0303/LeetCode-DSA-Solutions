class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>>ans=board;
        int n=board.size();
        int m=board[0].size();
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==1){
                int cnt=0;
                int drow[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
                int dcol[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
                for(int k=0;k<8;k++){
                    int n_row=i+drow[k];
                    int n_col=j+dcol[k];
                    if(n_row>=0 && n_col>=0 && n_row<n && n_col<m && board[n_row][n_col]==1)
                        cnt++;
                }
                if(cnt<2) ans[i][j]=0;
                if(cnt==2 || cnt==3) ans[i][j]=1;
                if(cnt>3) ans[i][j]=0;
                }
                else{
                   int cnt=0;
               
                 int drow[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
                int dcol[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
                for(int k=0;k<8;k++){
                    int n_row=i+drow[k];
                    int n_col=j+dcol[k];
                    if(n_row>=0 && n_col>=0 && n_row<n && n_col<m && board[n_row][n_col]==1)
                        cnt++;
                }
                if(cnt==3) ans[i][j]=1;
                }
            }
        }
        for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        board[i][j] = ans[i][j];
    }
}

    }
};