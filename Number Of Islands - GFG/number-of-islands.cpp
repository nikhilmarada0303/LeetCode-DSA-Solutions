//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
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
  bool isValid(int r,int c,int m,int n){                                                               //   tc:   k*4aplha*2*4
      return r>=0 && r<n && c>=0 && c<m;
  }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        disjointSet ds(n*m);
        int vis[n][m];
        memset(vis,0,sizeof vis);
        int cnt=0;
        vector<int>ans;
	 //   tc:   k*4aplha*2*4
        for(auto it:operators){
            int row=it[0];
            int col=it[1];
            if(vis[row][col]==1){
                    ans.push_back(cnt);
                    continue;
            }
            vis[row][col]=1;
            cnt++;
            int drow[4]={-1,0,1,0};
            int dcol[4]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int n_row=drow[i]+row;      
                int n_col=dcol[i]+col;
                if(isValid(n_row,n_col,m,n)){
                    if(vis[n_row][n_col]==1){                   // check if there is beside island
                        int adj_node_no=m*n_row+n_col;
                        int node_no=m*row+col;
                        if(ds.findParent(adj_node_no)!=ds.findParent(node_no)){
                            cnt--;
                            ds.unionBySize(node_no,adj_node_no);
                        }
                    }    
                }
            }ans.push_back(cnt);
        }return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends