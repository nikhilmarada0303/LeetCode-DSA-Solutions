//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
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
            if(newRow>=1 && newRow<n && newCol>=1 && newCol<m && !vis[newRow][newCol] && board[newRow][newCol]=='O')
                dfs(newRow,newCol,board,vis);
        }
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> board)
    {
        vector<vector<int>>vis(n,vector<int>(m,0));
        // traverse first row and last col 
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
        }return board;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends