class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>adj[n];
        for(auto it:roads){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
       int maxi=0;
        
        for(int i=0;i<n;i++){
            int cnt1=adj[i].size();
            int cnt2=0;
            for(int j=0;j<n;j++){
                if(i!=j){
                    cnt2=adj[j].size();
                    bool check=false;
                    for(auto it:adj[j]){
                        if(it==i) check=true;
                    }int cnt;
                    if(check)
                        cnt=cnt1+cnt2-1;
                    else cnt=cnt1+cnt2;
                    maxi=max(maxi,cnt);
                }
            }
            
        }return maxi;
    }
};