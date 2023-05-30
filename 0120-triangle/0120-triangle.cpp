class Solution {
public:
 
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
       vector<int>ahead(n,0);
       for(int j=0;j<n;j++)
           ahead[j]=triangle[n-1][j];
        for(int i=n-2;i>=0;i--){
            vector<int>curr(n,0);
            for(int j=i;j>=0;j--){
                int down=triangle[i][j]+ahead[j];
                int diag=triangle[i][j]+ahead[j+1];
                curr[j]=min(down,diag);
            }
            ahead=curr;
        }
        return ahead[0];
    }
};