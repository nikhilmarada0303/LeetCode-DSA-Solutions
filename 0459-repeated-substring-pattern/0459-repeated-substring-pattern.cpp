class Solution {
public:
    bool repeatedSubstringPattern(string s) {
       string t=s;
        for(int i=0;i<s.size()-1;i++){
            string c="";
            c=c+s[i];
            t.erase(0,1);
            t=t+c;
            
            if(t==s)
                 return true;
        }return false;
    }
};