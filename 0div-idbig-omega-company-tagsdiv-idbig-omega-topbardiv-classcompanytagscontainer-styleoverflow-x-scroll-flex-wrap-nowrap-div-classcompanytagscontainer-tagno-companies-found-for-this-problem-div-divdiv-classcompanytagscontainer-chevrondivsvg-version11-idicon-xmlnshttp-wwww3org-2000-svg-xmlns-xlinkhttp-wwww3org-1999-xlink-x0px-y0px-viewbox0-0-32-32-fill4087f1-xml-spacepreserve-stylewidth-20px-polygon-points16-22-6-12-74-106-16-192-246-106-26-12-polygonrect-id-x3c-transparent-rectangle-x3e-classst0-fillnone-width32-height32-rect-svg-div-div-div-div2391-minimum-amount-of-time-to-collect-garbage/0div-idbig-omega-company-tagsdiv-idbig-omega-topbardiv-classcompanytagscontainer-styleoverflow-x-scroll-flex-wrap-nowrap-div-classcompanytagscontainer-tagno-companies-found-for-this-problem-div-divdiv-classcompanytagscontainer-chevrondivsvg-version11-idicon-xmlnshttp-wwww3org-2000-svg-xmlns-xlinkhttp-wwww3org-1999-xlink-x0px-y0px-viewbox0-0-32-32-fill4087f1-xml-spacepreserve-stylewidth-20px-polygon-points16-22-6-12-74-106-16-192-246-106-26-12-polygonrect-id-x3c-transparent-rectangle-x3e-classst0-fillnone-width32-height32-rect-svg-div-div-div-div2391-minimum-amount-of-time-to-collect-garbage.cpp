class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        // map<char,int>mp;
        // for(auto it:garbage){
        //     for(int i=0;i<it.size();i++)
        //         mp[it[i]]++;
        // }
        // int n=mp.size();
        int ans=0;
        int last_m=-1;
        int last_p=-1;
        int last_g=-1;
        int cnt=0;
        for(int i=0;i<garbage.size();i++){
            for(int j=0;j<garbage[i].size();j++){
                cnt++;
                if(garbage[i][j]=='G')
                    last_g=i;
                if(garbage[i][j]=='P')
                    last_p=i;
                if(garbage[i][j]=='M')
                    last_m=i;
            }
        }
        ans=ans+cnt;
        if(last_m!=-1){
            for(int i=0;i<last_m;i++){
                ans=ans+travel[i];
            }
        }
         if(last_p!=-1){
            for(int i=0;i<last_p;i++){
                ans=ans+travel[i];
            }
        }
         if(last_g!=-1){
            for(int i=0;i<last_g;i++){
                ans=ans+travel[i];
            }
        }
        
        return ans;

    }
};