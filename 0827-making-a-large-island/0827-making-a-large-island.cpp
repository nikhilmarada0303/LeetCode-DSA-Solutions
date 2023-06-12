class disjointSet{
    public:
    vector<int>size,parent;
    disjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findParent(int node){
        if(node==parent[node]) return node;
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
      private:
    bool isValid(int r,int c ,int n){
        return r>=0 && r<n && c>=0 && c<n;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        disjointSet ds(n*n);
        int cnt=0;
        int drow[4]={-1,0,1,0};
        int dcol[4]={0,1,0,-1};
        // step1   store all diff compos 
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int row=i;
                int col=j;
                if(grid[i][j]==1){
                    cnt++;
                    for(int k=0;k<4;k++){
                        int n_row=drow[k]+row;
                        int n_col=dcol[k]+col;
                        if(isValid(n_row,n_col,n) && grid[n_row][n_col]==1){
                            int adj_node_no=n*n_row+n_col;
                            int node_no=n*row+col;
                            if(ds.findParent(adj_node_no)!=ds.findParent(node_no))
                                ds.unionBySize(adj_node_no,node_no);
                        }
                    }
                }
            }
        }
        //step2
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                set<int>components;
                int sizeTotal=0;
                if(grid[i][j]==0){
                     for(int k=0;k<4;k++){
                        int n_row=drow[k]+i;
                        int n_col=dcol[k]+j;
                            if(isValid(n_row,n_col,n) && grid[n_row][n_col]==1){
                                // some edge cases will fail ,will added twice
                            components.insert(ds.findParent(n_row*n+n_col));           
                            }
                      }
                }for(auto it:components){
                    sizeTotal+=ds.size[it];
                }maxi=max(maxi,sizeTotal+1);
            }
        }
        // if all are one's
        if(cnt==n*n) return n*n;
        return maxi;
    }
};