class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1 && i>0)
                    matrix[i][j]=matrix[i-1][j]+matrix[i][j];
            }
            vector<int>currRow=matrix[i];
            sort(currRow.begin(),currRow.end(),greater());
            
            for(int k=0;k<m;k++){
                ans=max(ans,(currRow[k]*(k+1)));
            }
        }
        return ans;
    }
};