class Solution {
    private:
        long long sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>nxtSmaller(n);
        vector<int>prevSmaller(n);
        stack<int>st;
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()) nxtSmaller[i]=n-1;
            else  nxtSmaller[i]=st.top()-1;
            st.push(i);
        }
        while(!st.empty()) st.pop();
        
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }if(st.empty()) prevSmaller[i]=0;
            else  prevSmaller[i]=st.top()+1;
            st.push(i);
        }
        long long sum=0;
        int mod=(int)(1e9+7);
       
        for(int i=0;i<n;i++){
            long t=arr[i];
            long h=t*((nxtSmaller[i]-i+1)*(i-prevSmaller[i]+1));
            sum=(sum+h);
        }return sum;
    }
    
        long long sumSubarrayMaxs(vector<int>& arr) {
        int n=arr.size();
        vector<int>nxtGreater(n);
        vector<int>prevGreater(n);
        stack<int>st;
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]<=arr[i]){
                st.pop();
            }
            if(st.empty()) nxtGreater[i]=n-1;
            else  nxtGreater[i]=st.top()-1;
            st.push(i);
        }
        while(!st.empty()) st.pop();
        
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]<arr[i]){
                st.pop();
            }if(st.empty()) prevGreater[i]=0;
            else  prevGreater[i]=st.top()+1;
            st.push(i);
        }
        long long sum=0;
        int mod=(int)(1e9+7);
       
        for(int i=0;i<n;i++){
            long t=arr[i];
            long h=t*((nxtGreater[i]-i+1)*(i-prevGreater[i]+1));
            sum=(sum+h);
        }return sum;
    }
public:
    long long subArrayRanges(vector<int>& nums) {
      return sumSubarrayMaxs(nums)-sumSubarrayMins(nums);
    }
};