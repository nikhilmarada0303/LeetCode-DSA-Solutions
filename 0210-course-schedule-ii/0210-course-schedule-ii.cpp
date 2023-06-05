class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {
          vector<int>adj[V];
	   for(auto it:prerequisites){
	       adj[it[1]].push_back(it[0]);
	   }
	    vector<int>in_degree(V,0);
	    for(int i=0;i<V;i++){
	        for(auto it:adj[i])
	            in_degree[it]++;
	    }
	    queue<int>q;
	    vector<int>topo;
	    for(int i=0;i<V;i++){
	        if(in_degree[i]==0)
	            q.push(i);
	    }
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        topo.push_back(node);
	        for(auto it:adj[node]){
	            in_degree[it]--;
	            if(in_degree[it]==0) 
	                q.push(it);
	        }
	    }
	    if(V==topo.size())
	        return topo;
	   return {};
    }
};