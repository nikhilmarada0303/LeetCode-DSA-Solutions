class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>>v=matrix;
        int n=matrix.size()-1;
        int m=matrix[0].size()-1;
        for(int i=n;i>=0;i--){
            for(int j=0;j<=m;j++){
                v[j][n-i]=matrix[i][j];
            }
        }matrix=v;
        
    }
};