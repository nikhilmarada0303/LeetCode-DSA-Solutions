class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int x=s1.size();
        int y=s2.size();
         vector<vector<int>>dp(x+1,vector<int>(y+1,0));
        for(int i=0;i<=x;i++)
            dp[i][0]=0;
        for(int i=0;i<=y;i++)
            dp[0][i]=0;
        for(int ind1=1;ind1<=x;ind1++){
            for(int ind2=1;ind2<=y;ind2++){                                         
                 if(s1[ind1-1]==s2[ind2-1])
                    dp[ind1][ind2]= 1+dp[ind1-1][ind2-1];
                else{
                dp[ind1][ind2]=max(dp[ind1-1][ind2],dp[ind1][ind2-1]);}
            }
        }
        
        int i=x;
        int j=y;
        string ans="";
        while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]){
                ans+=s1[i-1];
                i--;j--;
            }else if(dp[i-1][j]>dp[i][j-1]){
                ans+=s1[i-1];
                i--;
            }else{
                ans+=s2[j-1];
                j--;
            }
                
        }// base case at last either i or j will be remaining 
        while(i>0) {
            ans+=s1[i-1];
            i--;}
        while(j>0){
            ans+=s2[j-1];
            j--;}
        reverse(ans.begin(),ans.end());
        return ans;
    }
};