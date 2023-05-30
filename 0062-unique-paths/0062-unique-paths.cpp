class Solution {
public:
   
    int uniquePaths(int m, int n) {
        vector<int>prev(n,0);
        for(int i=0;i<m;i++){
            vector<int>curr(n,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0) curr[j]=1;
                else{
                int left=0,right=0;
                if(i>=1)
                left=prev[j];
                if(j>=1)
                right=curr[j-1];
                curr[j]=left+right;}
            }prev=curr;
        }
        return prev[n-1];
    }
};