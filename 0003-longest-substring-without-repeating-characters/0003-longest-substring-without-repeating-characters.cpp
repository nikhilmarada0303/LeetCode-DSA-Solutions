class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        map<char,int>mp;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(mp[s[j]]<1)
                    mp[s[j]]++;
                else if(mp[s[j]]==1)
                    break;
            }int g=mp.size();
            ans=max(ans,g);
            mp.clear();
        }
        return ans;
    }
};