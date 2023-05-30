//{ Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    //Function to find total number of unique paths.
    int NumberOfPath(int m, int n)
    {
                vector<int>prev(n,0);
        for(int i=0;i<m;i++){
            vector<int>curr(n,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0) curr[j]=1;
                else{
                int left=0,right=0;
                if(i>=1)
                left=prev[j];
                if(j>=1)
                right=curr[j-1];
                curr[j]=left+right;}
            }prev=curr;
        }
        return prev[n-1];
    }
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}


// } Driver Code Ends