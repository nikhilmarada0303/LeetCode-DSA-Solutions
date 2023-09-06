//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
    private:
    int largestRectangle(int nums[],int n) {
    //   int n=sizeof(nums);
       vector<int>left(n);
       vector<int>right(n);
        stack<int>st;
        
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(st.empty())
                left[i]=0;
            else 
                left[i]=st.top()+1;
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(st.empty())
                right[i]=n-1;
            else 
                right[i]=st.top()-1;
            st.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int d=abs(right[i]-left[i]+1)*nums[i];
            ans=max(ans,d);
        }return ans;
 }
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        int area=largestRectangle(M[0],m);
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
               if(M[i][j]!=0)
                    M[i][j]=M[i][j]+M[i-1][j];
                else 
                    M[i][j]=0;
            }
            area=max(area,largestRectangle(M[i],m));
        }return area;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends