//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int lcs(int x, int y, string s1, string s2)
    {
        vector<vector<int>>dp(x+1,vector<int>(y+1,0));
        for(int i=0;i<=x;i++)
            dp[i][0]=0;
        for(int i=0;i<=y;i++)
            dp[0][i]=0;
        for(int ind1=1;ind1<=x;ind1++){
            for(int ind2=1;ind2<=y;ind2++){                                          

                 if(s1[ind1-1]==s2[ind2-1])
                    dp[ind1][ind2]= 1+dp[ind1-1][ind2-1];
                else{
                dp[ind1][ind2]=max(dp[ind1-1][ind2],dp[ind1][ind2-1]);}
                 
            }
        }return dp[x][y];
      
    }

	int minOperations(string str1, string str2) 
	{ 
	    return str1.size()+str2.size()-2*lcs(str1.size(),str2.size(),str1,str2);
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends