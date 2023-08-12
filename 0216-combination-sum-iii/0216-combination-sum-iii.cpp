class Solution {
public:
    void func(int ind,int sum,vector<int>&ds,vector<vector<int>>&ans,int n,int k){
        if(ind==10){
            if(sum==n){
                if(ds.size()==k)
                    ans.push_back(ds);
            }
        return;
        }
        ds.push_back(ind);
        func(ind+1,sum+ind,ds,ans,n,k);
        ds.pop_back();
        func(ind+1,sum,ds,ans,n,k);
        return;
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>ds;
        vector<vector<int>>ans;
        func(1,0,ds,ans,n,k);
        return ans;
    }
};