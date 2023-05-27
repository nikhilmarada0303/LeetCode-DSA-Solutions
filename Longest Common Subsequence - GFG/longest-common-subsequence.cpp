//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    int lcs(int x, int y, string s1, string s2)
    {
       vector<int>prev(y+1,0),curr(y+1,0);
        for(int i=0;i<=y;i++)
            prev[i]=0;
        for(int ind1=1;ind1<=x;ind1++){
            for(int ind2=1;ind2<=y;ind2++){
                 if(s1[ind1-1]==s2[ind2-1])
                    curr[ind2]= 1+prev[ind2-1];
                else{
                curr[ind2]=max(prev[ind2],curr[ind2-1]);}
            }prev=curr;
        }return prev[y];
      
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends