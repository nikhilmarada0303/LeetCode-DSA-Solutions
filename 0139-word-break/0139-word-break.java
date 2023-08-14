class Solution {
    int dp[];
    public boolean wordBreak(String s, List<String> wordDict) {
        HashSet<String> hs = new HashSet<>();
        dp = new int[s.length()];
        Arrays.fill(dp,-1);
        for(String ss:wordDict)hs.add(ss);
        return f(0,s,hs);
    }
    
    boolean f(int i,String s,HashSet<String> hs){
        if(i == s.length())return true;
        
        if(dp[i]!=-1)return dp[i]==1;
        
        for(int j =i;j<s.length();j++){
            String sub = s.substring(i,j+1);
            if(hs.contains(sub)){
                if(f(j+1,s,hs)){
                    dp[i] = 1;
                    return true;}
            }
        }
        dp[i] = 0;
        return false;
    }
    
}