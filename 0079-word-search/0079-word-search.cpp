class Solution {
public:
    bool search(int row,int col,int index,vector<vector<char>>&grid,string s,int n,int m){
        if(index==s.size())
            return true;
        
        int drow[4]={-1,0,1,0};
        int dcol[4]={0,1,0,-1};
        char c=grid[row][col];
        grid[row][col]='!';
        
        for(int i=0;i<4;i++){
            int n_row=drow[i]+row;
            int n_col=dcol[i]+col;
            
            
            if(n_row>=0 && n_row<n && n_col>=0 && n_col<m && grid[n_row][n_col]!='!' &&                        grid[n_row][n_col]==s[index]){
                if(search(n_row,n_col,index+1,grid,s,n,m))
                        return true;
            }
            
        }
        grid[row][col]=c;
        return false;
    }
    bool exist(vector<vector<char>>& grid, string word) {
       int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==word[0]){
                    if(search(i,j,1,grid,word,n,m))
                        return true;
                }
            }
        }
        return false;
    }
};

