class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int ans=0;
        sort(piles.begin(),piles.end(),greater<int>());
        int g=piles.size()/3;
        int j=1;
        for(int i=0;i<g;i++){
            ans=ans+piles[j];
            j=j+2;
        }return ans;
    }
};