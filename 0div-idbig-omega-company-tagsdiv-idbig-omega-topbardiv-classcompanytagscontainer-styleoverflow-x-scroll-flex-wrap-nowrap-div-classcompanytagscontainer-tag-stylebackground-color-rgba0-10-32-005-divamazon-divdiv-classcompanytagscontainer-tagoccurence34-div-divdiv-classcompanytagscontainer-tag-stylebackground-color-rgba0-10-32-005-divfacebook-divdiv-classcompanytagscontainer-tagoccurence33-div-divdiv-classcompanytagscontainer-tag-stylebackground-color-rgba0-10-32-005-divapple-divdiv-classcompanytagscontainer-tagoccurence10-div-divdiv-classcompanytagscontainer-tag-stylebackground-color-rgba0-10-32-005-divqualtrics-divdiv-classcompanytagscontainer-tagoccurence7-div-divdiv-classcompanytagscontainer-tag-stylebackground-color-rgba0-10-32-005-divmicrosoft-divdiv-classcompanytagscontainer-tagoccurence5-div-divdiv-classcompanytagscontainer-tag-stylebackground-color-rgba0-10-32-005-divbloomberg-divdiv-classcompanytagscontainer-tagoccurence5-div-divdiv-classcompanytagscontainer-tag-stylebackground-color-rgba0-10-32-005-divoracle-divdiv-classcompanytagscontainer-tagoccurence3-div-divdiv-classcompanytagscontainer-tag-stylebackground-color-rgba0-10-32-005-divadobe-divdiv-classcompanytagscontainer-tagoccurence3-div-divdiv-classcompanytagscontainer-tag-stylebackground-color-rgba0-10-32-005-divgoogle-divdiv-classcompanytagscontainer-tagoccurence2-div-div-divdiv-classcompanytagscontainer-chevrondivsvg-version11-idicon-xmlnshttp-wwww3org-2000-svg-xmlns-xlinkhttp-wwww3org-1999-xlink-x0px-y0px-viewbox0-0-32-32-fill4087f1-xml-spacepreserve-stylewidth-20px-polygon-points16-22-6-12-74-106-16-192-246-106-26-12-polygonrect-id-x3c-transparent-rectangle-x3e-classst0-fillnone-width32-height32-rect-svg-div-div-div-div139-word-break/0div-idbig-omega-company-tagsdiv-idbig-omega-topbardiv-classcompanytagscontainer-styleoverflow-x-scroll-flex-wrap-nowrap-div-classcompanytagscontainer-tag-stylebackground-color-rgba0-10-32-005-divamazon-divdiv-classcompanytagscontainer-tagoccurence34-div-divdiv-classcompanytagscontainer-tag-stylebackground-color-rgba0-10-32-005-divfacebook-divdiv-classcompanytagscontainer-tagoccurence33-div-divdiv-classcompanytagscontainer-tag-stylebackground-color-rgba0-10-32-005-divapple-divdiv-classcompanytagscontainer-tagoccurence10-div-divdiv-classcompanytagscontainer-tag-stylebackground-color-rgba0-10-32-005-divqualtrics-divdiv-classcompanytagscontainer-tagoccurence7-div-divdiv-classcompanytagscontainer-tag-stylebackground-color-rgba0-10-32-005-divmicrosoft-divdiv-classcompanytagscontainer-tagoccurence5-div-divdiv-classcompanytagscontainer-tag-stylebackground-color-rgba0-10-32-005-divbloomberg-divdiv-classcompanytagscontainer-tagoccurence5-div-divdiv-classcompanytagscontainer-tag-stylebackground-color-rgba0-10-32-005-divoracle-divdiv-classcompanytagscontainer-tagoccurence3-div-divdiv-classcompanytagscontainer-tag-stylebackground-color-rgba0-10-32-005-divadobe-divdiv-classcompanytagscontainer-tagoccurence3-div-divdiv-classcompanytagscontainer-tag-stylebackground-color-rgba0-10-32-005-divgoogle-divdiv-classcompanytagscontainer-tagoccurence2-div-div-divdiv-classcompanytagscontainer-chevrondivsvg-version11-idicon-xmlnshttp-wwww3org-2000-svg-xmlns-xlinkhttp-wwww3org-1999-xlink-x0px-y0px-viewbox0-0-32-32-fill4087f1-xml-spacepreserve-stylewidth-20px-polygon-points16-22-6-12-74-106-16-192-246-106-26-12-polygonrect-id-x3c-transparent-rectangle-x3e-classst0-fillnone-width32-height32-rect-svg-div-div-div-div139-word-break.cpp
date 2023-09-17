class Solution {
public:
    bool func(int ind,vector<string>&wordDict,set<string>st,int n,string s,vector<int>&dp){
        if(ind==n){
            return true;
        }
        if(dp[ind]!=-1) return dp[ind];
        // cout<<ind<<" ";
        for(int i=ind;i<n;i++){
            string g=s.substr(ind,i-ind+1);
            if(st.find(g)!=st.end()){
                if(func(i+1,wordDict,st,n,s,dp))return true;
            }
        }return dp[ind]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>st;
        for(auto it:wordDict)
            st.insert(it);
       int n=s.size();
        vector<int>dp(s.size(),-1);
        return func(0,wordDict,st,n,s,dp);
    }
};
