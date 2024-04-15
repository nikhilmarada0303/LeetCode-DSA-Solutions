class Solution {
public:
    bool func(string g){
        int i=0;int j=g.size()-1;
        while(i<=j){
            if(g[i]!=g[j]){
                return false;
            }i++;j--;
        }return 1;
    }
    int countSubstrings(string s) {
        int cnt=0;
        for(int i=0;i<s.size();i++){
            string g="";
            for(int j=i;j<s.size();j++){
                g=g+s[j];
                if(func(g)){
                    cnt++;
                }
            }
        }return cnt;
    }
};