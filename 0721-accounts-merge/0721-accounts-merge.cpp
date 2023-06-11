class disjointSet{
    vector<int>size,parent;
    public:
        disjointSet(int n){
            size.resize(n+1,1);
            parent.resize(n+1);
            for(int i=0;i<=n;i++)
                parent[i]=i;
        }
        int findParent(int node){
            if(node==parent[node])
                return node;
            return parent[node]=findParent(parent[node]);
        }
        void unionBySize(int u,int v){
            int ult_u=findParent(u);
            int ult_v=findParent(v);
	    if(ult_u==ult_v) return;
            if(size[ult_u]<size[ult_v]){
                parent[ult_u]=ult_v;
                size[ult_v]+=size[ult_u];
            }
            else{
                parent[ult_v]=ult_u;
                size[ult_u]+=size[ult_v];
            }
        }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& details) {
         int n=details.size();
        disjointSet ds(n);
        unordered_map<string,int>mapMailnode;
        for(int i=0;i<n;i++){
            for(int j=1;j<details[i].size();j++){
                string mail=details[i][j];
                if(mapMailnode.find(mail)==mapMailnode.end())           // not there in map
                    mapMailnode[mail]=i;
                else{
                    ds.unionBySize(i,mapMailnode[mail]);
                }
            }
        }
        vector<string>mergeMail[n];
        for(auto it:mapMailnode){
            int name=ds.findParent(it.second);
            string mail=it.first;
            mergeMail[name].push_back(mail);
        }
        vector<vector<string>>ans;
       for(int i=0;i<n;i++){
            if(mergeMail[i].size()==0) continue;
            vector<string>temp;
            sort(mergeMail[i].begin(),mergeMail[i].end());
            temp.push_back(details[i][0]);
            for(auto it:mergeMail[i]){
                temp.push_back(it);
            }ans.push_back(temp);
        } 
        return ans;
    }
};