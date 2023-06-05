//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int V, vector<pair<int, int> >& prerequisites) {
	    // given a vector ,so convert it to adjacnecy list
	    vector<int>adj[V];
	   for(auto it:prerequisites){
	       adj[it.first].push_back(it.second);
	   }
	    vector<int>in_degree(V,0);
	    for(int i=0;i<V;i++){
	        for(auto it:adj[i])
	            in_degree[it]++;
	    }
	    queue<int>q;
	    int cnt=0;
	    for(int i=0;i<V;i++){
	        if(in_degree[i]==0)
	            q.push(i);
	    }
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        cnt++;
	        for(auto it:adj[node]){
	            in_degree[it]--;
	            if(in_degree[it]==0) 
	                q.push(it);
	        }
	    }
	    if(cnt==V) return true;
	    return false;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends