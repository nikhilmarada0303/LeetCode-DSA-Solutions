//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n=grid.size();
	    int m=grid[0].size();
	    queue<pair<pair<int,int>,int>>q;
	    vector<vector<int>>vis(n,vector<int>(m,0));
	    vector<vector<int>>dis(n,vector<int>(m,0));
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==1){
	                vis[i][j]=1;
	                q.push({{i,j},0});
	            }else
	                vis[i][j]=0;
	        }
	    }
	    int delRow[]={-1,0,1,0};
	    int delCol[]={0,1,0,-1};
	    while(!q.empty()){
	        int row=q.front().first.first;
	        int col=q.front().first.second;
	        int dist=q.front().second;
	        dis[row][col]=dist;
	        q.pop();
	        for(int i=0;i<4;i++){
	            int newRow=row+delRow[i];
	            int newCol=col+delCol[i];
	            if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && vis[newRow][newCol]==0 ){
	                vis[newRow][newCol]=1;
	                q.push({{newRow,newCol},dist+1});
	                 
	            }
	        }
	        
	    }return dis;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends