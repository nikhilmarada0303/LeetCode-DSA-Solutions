class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        stack<int>st;
        int n=nums.size();
        vector<int>v(n,0);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<=nums[i])
                st.pop();
            if(st.empty()){
                v[i]=0;
            }else{
                v[i]=st.top()-i;
            }st.push(i);
        }return v;
    }
};