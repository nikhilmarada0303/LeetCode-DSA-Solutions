//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    int celebrity(vector<vector<int> >& arr, int n) 
    {
         if (n == 1) {
        return 0;
    }
        for(int i=0;i<n;i++){
            bool row=false;
            bool col=false;
            for(int j=0;j<n;j++){
                if(arr[i][j]==0 )
                    row=true;
                else if(i!=j && arr[i][j]==1){
                    row=false;
                    break;}
            }
            for(int j=0;j<n;j++){
                if(arr[j][i]==1 && j!=i)
                    col=true;
                else if(j!=i && arr[j][i]==0){
                    col=false;
                    break;        
                }
            }
            if(col && row){
                for (int j = 0; j < n; j++) {
                if (i != j && (arr[i][j] == 1 || arr[j][i] == 0)) {
                    return -1; // The potential celebrity is not a celebrity
                }
            }
                return i;}
        }return -1;
        
        // stack<int>st;
        // for(int i=n-1;i>=0;i--)
        //     st.push(i);
            
        // while(st.size()>1){
        //     int a=st.top();
        //     st.pop();
            
        //     int b=st.top();
        //     st.pop();
            
        //     if(arr[a][b]==1)
        //         st.push(b);
        //     else 
        //         st.push(a);
        // }
        // int ans=st.top();
        
        // for(int i=0;i<arr[ans].size();i++){         //row check
        //     if(arr[ans][i]==1 && i!=ans) return -1;
        // }
        // for(int i=0;i<arr.size();i++){
        //     if(arr[i][ans]==0 && ans!=i) return -1;
        // }
        // return ans;
        
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends