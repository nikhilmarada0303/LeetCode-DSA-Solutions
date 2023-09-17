class Solution {
public:
    bool isPalindrome(string c){
      int i=0;
        int j=c.size()-1;
        while(i<=j){
            if(c[i]!=c[j]) return false;
            i++;j--;
        }return true;
    }
    void func(int ind,vector<string>&ds,vector<vector<string>>&ans,string s){
        if(ind==s.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<s.size();i++){
            string c=s.substr(ind,i-ind+1);
            if(isPalindrome(c)){
                ds.push_back(s.substr(ind, i - ind + 1));
                func(i+1,ds,ans,s);
                ds.pop_back();
            }
        }return ;
    }
    vector<vector<string>> partition(string s) {
        vector<string>ds;
        vector<vector<string>>ans;
        func(0,ds,ans,s);
        return ans;
    }
};