class Solution {
   private:
    void dfs(int row,int col,vector<vector<int>>&image,vector<vector<int>>&ans,int iniColor,int newColor){
        ans[row][col]=newColor;
        int n=image.size(); int m=image[0].size();
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                if((i==-1 && j==-1) || (i==1 && j==1) || (i==-1 && j==1) || (i==1 && j==-1)) continue;
                else{
                int newRow=row+i;
                int newCol=col+j;
                 if(newRow>=0 and newRow<n and newCol>=0 and newCol<m and
               ans[newRow][newCol]!=newColor and ans[newRow][newCol]==iniColor)
                dfs(newRow,newCol,image,ans,iniColor,newColor);
                    
                }
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<int>>ans=image;
        int iniColor=ans[sr][sc];
        dfs(sr,sc,image,ans,iniColor,newColor);
        return ans;
    }


};