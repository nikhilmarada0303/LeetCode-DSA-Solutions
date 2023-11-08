class Solution {
    private:
    int func(int k){
        int cnt=0;
        while(k){
            if(1 & k){
                cnt++;
            }
            k=k>>1;
        }return cnt;
    }
public:
    vector<int> countBits(int n) {
        vector<int>ans(n+1);
        for(int i=0;i<=n;i++){
            int bits=func(i);
            ans[i]=bits;
        }return ans;
    }
};