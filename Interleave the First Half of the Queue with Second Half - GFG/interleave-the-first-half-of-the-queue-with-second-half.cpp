//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        queue<int>q1;
        int size=q.size();
        for(int i=0;i<size/2;i++){
            int num=q.front();
            q.pop();
            q1.push(num);
        }
        for(int i=0;i<size/2;i++){
            int n1=q1.front();
            q1.pop();
            q.push(n1);
            int n2=q.front();
            q.pop();
            q.push(n2);
        }
        vector<int>v;
        while(!q.empty()){
            v.push_back(q.front());
            q.pop();
        }return v;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        queue<int> q;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            q.push(a);
        }
        Solution ob;
        vector<int> ans=ob.rearrangeQueue(q);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
// } Driver Code Ends