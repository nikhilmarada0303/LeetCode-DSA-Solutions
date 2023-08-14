//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// class Solution{
//     public:
//     void func(int row,int col,vector<vector<int>>&m,vector<vector<int>>&vis,int n,
//     string s,vector<string>&ans){
//         if(row==n-1 && col==n-1){
//             ans.push_back(s);
//             return ;
//         }
//         if(row+1<n){
//             if(!vis[row+1][col] && m[row+1][col]==1){
//                 vis[row+1][col]=1;
//                 func(row+1,col,m,vis,n,s+"D",ans);
//                 vis[row+1][col]=0;
//             }
//         }
//         if(row-1>=0){
//             if(!vis[row-1][col] && m[row-1][col]==1){
//                 vis[row-1][col]=1;
//                 func(row-1,col,m,vis,n,s+"U",ans);
//                 vis[row-1][col]=0;
//             }
//         }
        
//         if( col+1<n){
//             if(!vis[row][col+1] && m[row][col+1]==1){
//                 vis[row][col+1]=1;
//                 func(row,col+1,m,vis,n,s+"R",ans);
//                 vis[row][col+1]=0;
//             }
//         }
//          if(col-1>=0){
//             if(!vis[row][col-1] && m[row][col-1]==1){
//                 vis[row][col-1]=1;
//                 func(row,col-1,m,vis,n,s+"L",ans);
//                  vis[row][col-1]=0;
//             }
//         }
//         return;
//     }

//     vector<string> findPath(vector<vector<int>> &m, int n) {
//         string s="";
//         vector<string>ans;
//         vector<vector<int>>vis(n,vector<int>(n,0));
//         if(m[0][0]==1)
//         func(0,0,m,vis,n,s,ans);
//         return ans;
//     }
// };
class Solution {
  void findPathHelper(int i, int j, vector < vector < int >> & a, int n, vector < string > & ans, string move,
    vector < vector < int >> & vis) {
    if (i == n - 1 && j == n - 1) {
      ans.push_back(move);
      return;
    }

    // downward
    if (i + 1 < n && !vis[i + 1][j] && a[i + 1][j] == 1) {
      vis[i][j] = 1;
      findPathHelper(i + 1, j, a, n, ans, move + 'D', vis);
      vis[i][j] = 0;
    }

    // left
    if (j - 1 >= 0 && !vis[i][j - 1] && a[i][j - 1] == 1) {
      vis[i][j] = 1;
      findPathHelper(i, j - 1, a, n, ans, move + 'L', vis);
      vis[i][j] = 0;
    }

    // right 
    if (j + 1 < n && !vis[i][j + 1] && a[i][j + 1] == 1) {
      vis[i][j] = 1;
      findPathHelper(i, j + 1, a, n, ans, move + 'R', vis);
      vis[i][j] = 0;
    }

    // upward
    if (i - 1 >= 0 && !vis[i - 1][j] && a[i - 1][j] == 1) {
      vis[i][j] = 1;
      findPathHelper(i - 1, j, a, n, ans, move + 'U', vis);
      vis[i][j] = 0;
    }

  }
  public:
    vector < string > findPath(vector < vector < int >> & m, int n) {
      vector < string > ans;
      vector < vector < int >> vis(n, vector < int > (n, 0));

      if (m[0][0] == 1) findPathHelper(0, 0, m, n, ans, "", vis);
      return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends