class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
         stack<int>st;
   for(int i=0;i<arr.size();i++){
         while(!st.empty() && arr[i]<0 && st.top()>0) {
             int a=st.top();
             int sum=arr[i]+a;
             if(sum<0) st.pop();
             else if(sum>0) arr[i]=0;
             else{
                 st.pop();
                 arr[i]=0;
             }
         }
         if(arr[i]!=0) st.push(arr[i]);
       
   }vector<int>v;
   while(!st.empty()){
       v.push_back(st.top());
       st.pop();
   }reverse(v.begin(),v.end());
   return v;
    }
};