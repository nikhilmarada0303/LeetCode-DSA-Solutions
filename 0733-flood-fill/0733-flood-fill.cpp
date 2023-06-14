class Solution {
    private:
    void dfs(int row,int col,vector<vector<int>>&image,vector<vector<int>>&ans,int color,int inicolor,int drow[],int dcol[],int m,int n){
       ans[row][col]=color;
        for(int i=0;i<4;i++){
            int n_row=row+drow[i];
            int n_col=col+dcol[i];
            if(n_row>=0 && n_row<m && n_col>=0 && n_col<n && image[n_row][n_col]==inicolor && ans[n_row][n_col]!=color){
                dfs(n_row,n_col,image,ans,color,inicolor,drow,dcol,m,n);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inicolor=image[sr][sc];
        vector<vector<int>>ans=image;
        int m=image.size();
        int n=image[0].size();
        int drow[4]={-1,0,1,0};
        int dcol[4]={0,1,0,-1};
        dfs(sr,sc,image,ans,color,inicolor,drow,dcol,m,n);
        return ans;
    }
};