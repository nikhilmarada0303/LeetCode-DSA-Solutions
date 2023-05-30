//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int n, vector<vector<int>> matrix)
    {
         
        int m=n;
       vector<int>prev(m,0);
        for(int j=0;j<m;j++)
            prev[j]=matrix[0][j];
        
        for(int i=1;i<n;i++){
            vector<int>curr(m,0);
            for(int j=0;j<m;j++){
                int up=matrix[i][j]+prev[j];
                int diag1=0,diag2=0;
                if(j>=1)
                    diag1=matrix[i][j]+prev[j-1];
                else
                    diag1=-1e8;
                if(j+1<m)
                     diag2=matrix[i][j]+prev[j+1];
                else
                    diag2=-1e8;
                curr[j]=max(up,max(diag1,diag2));
            }prev=curr;
        }
        int maxi=-1e8;
        for(int j=0;j<m;j++){
            maxi=max(maxi,prev[j]);
        }return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends