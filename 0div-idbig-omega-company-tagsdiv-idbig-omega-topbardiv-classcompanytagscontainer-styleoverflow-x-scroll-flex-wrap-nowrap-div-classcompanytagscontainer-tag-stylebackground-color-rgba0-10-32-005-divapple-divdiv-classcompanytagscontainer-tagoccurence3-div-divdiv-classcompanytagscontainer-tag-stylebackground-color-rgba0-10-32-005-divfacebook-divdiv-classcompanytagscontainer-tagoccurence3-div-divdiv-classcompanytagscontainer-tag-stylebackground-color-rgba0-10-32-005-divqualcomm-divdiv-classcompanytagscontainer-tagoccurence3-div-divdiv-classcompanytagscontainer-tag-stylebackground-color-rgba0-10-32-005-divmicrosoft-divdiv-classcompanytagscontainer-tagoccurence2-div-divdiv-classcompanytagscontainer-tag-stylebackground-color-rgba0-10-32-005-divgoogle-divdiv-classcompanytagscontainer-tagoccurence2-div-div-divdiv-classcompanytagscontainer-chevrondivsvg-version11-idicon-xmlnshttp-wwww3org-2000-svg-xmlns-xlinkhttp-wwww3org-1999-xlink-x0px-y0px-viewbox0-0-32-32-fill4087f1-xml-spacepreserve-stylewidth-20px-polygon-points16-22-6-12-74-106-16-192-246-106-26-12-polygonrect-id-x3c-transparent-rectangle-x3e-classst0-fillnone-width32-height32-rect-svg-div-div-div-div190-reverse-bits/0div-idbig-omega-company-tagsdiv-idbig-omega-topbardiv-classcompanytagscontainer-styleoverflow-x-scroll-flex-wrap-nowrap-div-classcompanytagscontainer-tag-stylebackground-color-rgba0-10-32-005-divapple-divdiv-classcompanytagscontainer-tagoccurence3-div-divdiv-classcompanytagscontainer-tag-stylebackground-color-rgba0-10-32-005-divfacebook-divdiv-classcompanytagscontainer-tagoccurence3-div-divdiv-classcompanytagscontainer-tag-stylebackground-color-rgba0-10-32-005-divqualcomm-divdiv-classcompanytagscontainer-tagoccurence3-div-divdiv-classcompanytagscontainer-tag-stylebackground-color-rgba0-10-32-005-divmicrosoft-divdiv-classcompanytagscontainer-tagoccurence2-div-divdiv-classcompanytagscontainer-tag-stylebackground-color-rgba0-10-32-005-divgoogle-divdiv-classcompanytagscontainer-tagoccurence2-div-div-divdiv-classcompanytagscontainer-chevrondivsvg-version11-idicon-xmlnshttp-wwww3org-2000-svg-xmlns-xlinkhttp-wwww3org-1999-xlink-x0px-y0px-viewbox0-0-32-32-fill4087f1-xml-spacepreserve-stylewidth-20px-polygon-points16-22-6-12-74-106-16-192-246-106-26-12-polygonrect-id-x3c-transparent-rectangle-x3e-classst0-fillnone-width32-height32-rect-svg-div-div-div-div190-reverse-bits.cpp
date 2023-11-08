class Solution {
    private:
    bool set(int k,uint32_t n){
        if((1<<(k-1)&n))
            return true;
        return false;
    }
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0;
        for(int i=1;i<=32;i++){
            if(set(i,n)){
                ans=ans | (1<<32-i);
            }
        }return ans;
    }
};