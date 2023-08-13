class Solution {
public:
    bool isSafe(int row,int col,vector<string>&board){
        int nrow=row;
        int ncol=col;
        while(row>=0 && col>=0){
            if(board[row][col]=='Q') return false;
            row--;
            col--;
        }
        row=nrow;
        col=ncol;
        while(col>=0){
            if(board[row][col]=='Q') return false;
            col--;
        }
        row=nrow;
        col=ncol;
        while(col>=0 && row<board.size()){
            if(board[row][col]=='Q') return false;
            row++;
            col--;
        }
        return true;
    }
    void func(int col,vector<string>&board,vector<vector<string>>&ans,int n){
        if(col==n){
            ans.push_back(board);
            return ;
        }
        for(int row=0;row<n;row++){
            if(isSafe(row,col,board)){
                board[row][col]='Q';
                func(col+1,board,ans,n);
                board[row][col]='.';
            }
        }return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        vector<vector<string>>ans;
        func(0,board,ans,n);
        return ans;
    }
};