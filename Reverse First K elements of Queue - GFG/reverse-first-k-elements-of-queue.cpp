//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends


void func(int k,queue<int>&q){
    if(k==0){
        return ;
    }
    int num=q.front();
    q.pop();
    func(k-1,q);
    q.push(num);
    return ;
}
queue<int> modifyQueue(queue<int> q, int k) {
    int n=q.size();
    func(k,q);
    for(int i=0;i<n-k;i++){
        int n=q.front();
        q.pop();
        q.push(n);
    }return q;
}