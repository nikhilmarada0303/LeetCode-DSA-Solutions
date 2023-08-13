class Solution {
public:
    bool isPalindrome(int start,int end,string s){
        while(start<=end){
            if(s[start]!=s[end])
                return false;
            start++;
            end--;
        }return true;
    }
    void func(int ind,vector<string>&ds,vector<vector<string>>&ans,string s){
        if(ind==s.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<s.size();i++){
            if(isPalindrome(ind,i,s)){
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