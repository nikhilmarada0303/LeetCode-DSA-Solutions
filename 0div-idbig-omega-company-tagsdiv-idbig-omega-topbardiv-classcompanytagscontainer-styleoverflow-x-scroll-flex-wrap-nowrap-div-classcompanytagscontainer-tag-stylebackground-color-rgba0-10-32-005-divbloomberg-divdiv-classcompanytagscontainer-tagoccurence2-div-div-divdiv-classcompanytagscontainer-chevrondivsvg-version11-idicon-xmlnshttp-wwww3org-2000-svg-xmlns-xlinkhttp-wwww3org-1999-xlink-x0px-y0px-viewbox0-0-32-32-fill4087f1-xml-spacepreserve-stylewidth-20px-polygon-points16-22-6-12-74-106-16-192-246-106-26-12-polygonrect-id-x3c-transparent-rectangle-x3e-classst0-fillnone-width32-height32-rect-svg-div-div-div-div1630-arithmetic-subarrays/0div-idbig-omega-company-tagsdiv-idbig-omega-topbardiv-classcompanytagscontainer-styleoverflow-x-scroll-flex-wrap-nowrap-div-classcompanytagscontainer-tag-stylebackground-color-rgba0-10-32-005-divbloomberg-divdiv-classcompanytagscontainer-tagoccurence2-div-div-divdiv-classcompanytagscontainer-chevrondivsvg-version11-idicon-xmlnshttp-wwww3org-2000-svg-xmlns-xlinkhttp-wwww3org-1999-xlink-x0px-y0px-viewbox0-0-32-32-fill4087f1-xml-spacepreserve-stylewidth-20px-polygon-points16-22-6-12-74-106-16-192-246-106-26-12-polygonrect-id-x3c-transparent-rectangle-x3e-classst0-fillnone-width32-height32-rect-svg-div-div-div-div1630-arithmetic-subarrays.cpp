class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool>ans;
        for(int i=0;i<l.size();i++){
            int a=l[i];
            int b=r[i];
            int g=b-a+1;
            vector<int>c(nums.begin()+a,nums.begin()+b+1);
            // for(int j=a;j<=b;j++){
            //     c.push_back(nums[j]);
            // }
            sort(c.begin(),c.end());
            int flag=0;
            int diff=c[1]-c[0];
            for(int k=1;k<c.size();k++){
               if(c[k]-c[k-1]!=diff){
                   flag=1;
                    break;
               }
            }
            if(flag!=1)
                ans.push_back(true);
            else
                ans.push_back(false);
        }return ans;
    }
};