class Solution {
public:
//     int func(int ind1,int ind2,string s,string t,vector<vector<int>>&dp){
//         if(ind2<0) return 1;
//         if(ind1<0) return 0;
        
//         if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
//         if(s[ind1]==t[ind2]){
//             return dp[ind1][ind2]=func(ind1-1,ind2-1,s,t,dp)+func(ind1-1,ind2,s,t,dp);
//         }
//         return dp[ind1][ind2]=func(ind1-1,ind2,s,t,dp);
        
//     }
//     int numDistinct(string s, string t) {
//         int n=s.size();
//         int m=t.size();
//         vector<double>prev(m+1,0);
//         prev[0]=1;
        
//         for(int ind1=1;ind1<=n;ind1++){
//             for(int ind2=m;ind2>=1;ind2--){
//                 if(s[ind1-1]==t[ind2-1]){
//                 prev[ind2]=prev[ind2-1]+prev[ind2];
//         }
           
//             };
//         }return (int)prev[m];
//     }
     int func(int ind1,int ind2,string s,string t, vector<vector<int>>&dp){
        if(ind2<0) return 1;
        if(ind1<0) return 0;
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(s[ind1]==t[ind2])
            return dp[ind1][ind2]=func(ind1-1,ind2-1,s,t,dp)+func(ind1-1,ind2,s,t,dp);
        else return  dp[ind1][ind2]=func(ind1-1,ind2,s,t,dp);
    }
public:
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return func(n-1,m-1,s,t,dp);
    }

};