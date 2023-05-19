//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        // code here 
          stack<string>st;
        for(int i=0;i<s.size();i++){
            string l="";
            while(i<s.size() && s[i]!='.'){
                l=l+s[i];
                i++;
            }st.push(l);
        }string g="";
        while(!st.empty()){
            g=g+st.top();
            st.pop();
            if(!st.empty())
            g=g+'.';
        }return g;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends