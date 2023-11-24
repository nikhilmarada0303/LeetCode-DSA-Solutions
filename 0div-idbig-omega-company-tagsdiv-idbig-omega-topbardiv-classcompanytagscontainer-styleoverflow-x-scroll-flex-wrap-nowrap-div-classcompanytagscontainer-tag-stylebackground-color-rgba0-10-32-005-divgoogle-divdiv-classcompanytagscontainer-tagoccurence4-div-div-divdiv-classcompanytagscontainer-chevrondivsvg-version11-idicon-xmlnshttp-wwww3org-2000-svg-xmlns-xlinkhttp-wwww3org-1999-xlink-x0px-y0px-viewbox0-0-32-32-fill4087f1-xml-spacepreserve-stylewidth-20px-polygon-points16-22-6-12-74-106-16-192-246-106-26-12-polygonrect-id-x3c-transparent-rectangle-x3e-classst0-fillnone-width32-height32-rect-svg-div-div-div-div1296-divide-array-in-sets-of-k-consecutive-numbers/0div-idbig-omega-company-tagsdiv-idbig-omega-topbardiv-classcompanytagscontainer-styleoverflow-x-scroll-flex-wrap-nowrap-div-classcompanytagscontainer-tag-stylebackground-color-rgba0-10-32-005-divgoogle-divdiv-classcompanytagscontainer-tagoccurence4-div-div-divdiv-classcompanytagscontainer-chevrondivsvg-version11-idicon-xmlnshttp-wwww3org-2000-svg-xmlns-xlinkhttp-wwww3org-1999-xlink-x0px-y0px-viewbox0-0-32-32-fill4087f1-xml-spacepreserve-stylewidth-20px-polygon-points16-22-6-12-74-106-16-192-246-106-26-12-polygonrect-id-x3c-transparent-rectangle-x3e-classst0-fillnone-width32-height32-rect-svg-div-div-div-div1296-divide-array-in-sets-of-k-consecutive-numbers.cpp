class Solution {
    private:
    bool func(vector<int>&v){
        for(int i=1;i<v.size();i++){
            if(v[i]-v[i-1]!=1)
                return false;
        }return true;
    }
   
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>mp;
        for(auto it:nums)
            mp[it]++;
        
        int check=n/k;
        if(n%k!=0) return false;
        vector<int>v;
        int cnt=0;
       for(int i=0;i<check;i++){
               for(auto it:mp){
                   if(cnt<k && it.second>0){
                   v.push_back(it.first);
                   mp[it.first]--; 
                   cnt++;
               }
           }if(cnt!=k || !func(v))
               return false;
            cnt=0;
           v.clear();
       }return true;
    }
};