//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
       int m=grid.size();
       int n=grid[0].size();
       int vis[m][n];
       int cntFresh=0;
       //{time,{r,c}}
       queue<pair<int,pair<int,int>>>q;
       for(int i=0;i<m;i++){
           for(int j=0;j<n;j++){
               if(grid[i][j]==2){
                   q.push({0,{i,j}});
                   vis[i][j]=1;
               }else
                vis[i][j]=0;
                if(grid[i][j]==1)
                    cntFresh++;    //fresh oranges
           }
       }
       int tmin=0;
       int drow[4]={-1,0,1,0};
       int dcol[4]={0,1,0,-1};
       int cnt=0;
       while(!q.empty()){
           int time=q.front().first;
           int row=q.front().second.first;
           int col=q.front().second.second;
           q.pop();
           tmin=time;
           for(int i=0;i<4;i++){
               int n_row=row+drow[i];
               int n_col=col+dcol[i];
               if(n_row>=0 && n_row<m && n_col>=0 && n_col<n && vis[n_row][n_col]==0 && grid[n_row][n_col]==1){
                   vis[n_row][n_col]=1;
                   q.push({time+1,{n_row,n_col}});
                   cnt++;
               }
           }
           
       }if(cnt==cntFresh)
        return tmin;
        return -1;
       
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends