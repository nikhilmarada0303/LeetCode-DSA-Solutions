class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int>v(n);
       vector<int>f_sum(n,0);
        vector<int>b_diff(n,0);
        
        f_sum[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            f_sum[i]=f_sum[i+1]+nums[i];
        }
        b_diff[0]=0;
        for(int i=1;i<n;i++){
            b_diff[i]=nums[i-1]+b_diff[i-1];
        }
        for(int i=0;i<n;i++){
            int t=i;
            int a=abs(f_sum[i]-((n-i)*nums[i]));
            int b=abs(b_diff[i]-(i*nums[i]));
            int c=abs(a+b);
            v[i]=c;
        }return v;
    }
};

