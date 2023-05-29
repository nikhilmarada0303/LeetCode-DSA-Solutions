class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
      vector<long long>front1(2,0);
         vector<long long>front2(2,0);
         vector<long long>curr(2,0);
        for(int ind=n-1;ind>=0;ind--){
                 curr[1]=max(-prices[ind]+front1[0],0+front1[1]);
                 curr[0]=max(prices[ind]+front2[1],0+front1[0]);
                front2=front1;
                front1=curr;
        
        }return curr[1];
    }
};