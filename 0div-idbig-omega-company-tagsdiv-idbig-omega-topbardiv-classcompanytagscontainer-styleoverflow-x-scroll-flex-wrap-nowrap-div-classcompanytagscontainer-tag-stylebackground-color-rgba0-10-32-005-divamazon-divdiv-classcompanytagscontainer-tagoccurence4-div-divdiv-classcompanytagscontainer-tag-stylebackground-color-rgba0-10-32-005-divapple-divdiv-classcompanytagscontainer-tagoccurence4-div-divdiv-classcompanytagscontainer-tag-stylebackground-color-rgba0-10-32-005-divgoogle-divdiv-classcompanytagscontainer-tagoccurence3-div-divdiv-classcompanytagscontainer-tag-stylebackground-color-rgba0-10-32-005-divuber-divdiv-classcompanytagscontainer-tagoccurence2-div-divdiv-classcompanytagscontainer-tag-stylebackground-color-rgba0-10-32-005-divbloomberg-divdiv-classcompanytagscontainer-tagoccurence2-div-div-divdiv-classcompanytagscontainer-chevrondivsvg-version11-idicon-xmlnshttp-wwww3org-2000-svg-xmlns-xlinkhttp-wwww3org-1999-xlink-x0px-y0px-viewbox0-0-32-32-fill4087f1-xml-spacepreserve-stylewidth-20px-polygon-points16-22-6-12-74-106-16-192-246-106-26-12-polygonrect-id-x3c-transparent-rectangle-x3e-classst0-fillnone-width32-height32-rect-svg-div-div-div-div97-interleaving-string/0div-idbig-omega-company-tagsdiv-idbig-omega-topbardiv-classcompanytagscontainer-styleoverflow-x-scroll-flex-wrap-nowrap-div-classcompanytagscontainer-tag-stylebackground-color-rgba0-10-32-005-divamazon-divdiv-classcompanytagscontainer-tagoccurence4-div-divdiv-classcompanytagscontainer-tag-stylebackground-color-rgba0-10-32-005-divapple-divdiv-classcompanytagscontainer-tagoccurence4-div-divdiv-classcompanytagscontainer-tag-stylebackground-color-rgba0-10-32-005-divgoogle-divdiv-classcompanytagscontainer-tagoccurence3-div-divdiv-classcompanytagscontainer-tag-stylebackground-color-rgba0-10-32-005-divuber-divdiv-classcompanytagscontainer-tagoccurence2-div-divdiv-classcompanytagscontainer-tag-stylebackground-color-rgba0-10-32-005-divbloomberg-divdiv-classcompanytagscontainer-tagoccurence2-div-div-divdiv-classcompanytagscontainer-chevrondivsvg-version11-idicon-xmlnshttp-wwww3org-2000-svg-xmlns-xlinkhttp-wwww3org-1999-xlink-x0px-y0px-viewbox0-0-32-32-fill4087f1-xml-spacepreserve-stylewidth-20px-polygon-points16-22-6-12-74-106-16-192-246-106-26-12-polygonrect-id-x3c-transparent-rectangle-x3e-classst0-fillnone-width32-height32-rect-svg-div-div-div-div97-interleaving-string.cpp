class Solution {
    bool func(int i,int j,int k,int m,int n,int N,string &s1,string &s2,string &s3, vector<vector<vector<int>>>&dp){
        if(i>=m && j>=n && k>=N) return true;
        if(k>=N) return false;
        int result=0;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        int take=0;
        int not_take=0;
        if(s1[i]==s3[k]){
            take=func(i+1,j,k+1,m,n,N,s1,s2,s3,dp);
        }
        // if(result==true) return dp[i][j][k]=true;
        
        if(s2[j]==s3[k]){
            not_take=func(i,j+1,k+1,m,n,N,s1,s2,s3,dp);
        }
        return dp[i][j][k]=take || not_take;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m=s1.size();
        int n=s2.size();
        int N=s3.size();
        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(N+1,-1)));
        if(func(0,0,0,m,n,N,s1,s2,s3,dp)) return 1;
        return 0;
    }
};