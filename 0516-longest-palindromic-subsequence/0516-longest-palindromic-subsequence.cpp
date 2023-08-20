class Solution {
public:
    // void func(int ind,string s,string v,vector<string>&ans){
    //     if(ind==-1){
    //         ans.push_back(v);
    //         return ;
    //     }
    //     func(ind-1,s,v+s[ind],ans);
    //     func(ind-1,s,v,ans);
    //     return ;
    // }
    // bool isPalindrome(string r){
    //     int l=0;
    //     int h=r.size()-1;
    //     while(l<=h){
    //         if(r[l]!=r[h]) return false;
    //         l++;
    //         h--;
    //     }return true;
    // }
    int longestPalindromeSubseq(string s1) {
//         string v="";
//         vector<string>ans;
//         func(s.size()-1,s,v,ans);
        
//         int len=0;
//         for(int i=0;i<ans.size();i++){
//             if(isPalindrome(ans[i])){
//                 int z=ans[i].size();
//                 len=max(len,z);
//             }
//         }return len;
        string s2=s1;
        reverse(s2.begin(),s2.end());
        int n=s1.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=n;ind2++){
                if(s1[ind1-1]==s2[ind2-1])
                    dp[ind1][ind2]=1+dp[ind1-1][ind2-1];
                else{
                    dp[ind1][ind2]=max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
                }
            }
        }return dp[n][n];
    }
};