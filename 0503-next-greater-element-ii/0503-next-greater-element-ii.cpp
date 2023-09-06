class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n=arr.size();
         vector<int>v(n);
    stack<int>st;

    for(int i=2*n-1;i>=0;i--){
        while(!st.empty() && st.top()<=arr[i%n])
            st.pop();
		if(st.empty()){
			v[i%n]=-1;
		}else
        v[i%n]=st.top();
        st.push(arr[i%n]);
    }
    return v;
    }
};