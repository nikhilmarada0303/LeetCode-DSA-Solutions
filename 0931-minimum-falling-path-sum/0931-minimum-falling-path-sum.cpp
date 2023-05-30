class Solution {
public:
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
         int n=matrix.size();
        int m=matrix[0].size();
       vector<int>prev(m,0);
        for(int j=0;j<m;j++)
            prev[j]=matrix[0][j];
        
        for(int i=1;i<n;i++){
            vector<int>curr(m,0);
            for(int j=0;j<m;j++){
                int up=matrix[i][j]+prev[j];
                int diag1=0,diag2=0;
                if(j>=1)
                    diag1=matrix[i][j]+prev[j-1];
                else
                    diag1=1e8;
                if(j+1<m)
                     diag2=matrix[i][j]+prev[j+1];
                else
                    diag2=1e8;
                curr[j]=min(up,min(diag1,diag2));
            }prev=curr;
        }
        int mini=1e8;
        for(int j=0;j<m;j++){
            mini=min(mini,prev[j]);
        }return mini;
    }
};