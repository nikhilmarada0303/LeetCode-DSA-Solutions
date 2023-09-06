class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        int n=nums.size();
       vector<int>left(n);
       vector<int>right(n);
        stack<int>st;
        
        for(int i=0;i<nums.size();i++){
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
};